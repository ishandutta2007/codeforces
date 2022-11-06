#include <cstdio>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Maxn=300000;
const int Maxm=20;
const int Mod=998244353;
int frac[Maxn+5],inv_f[Maxn+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=Maxn;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn]=quick_power(frac[Maxn],Mod-2,Mod);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	if(n<m){
		return 0;
	}
	if(m<0){
		return 0;
	}
	return 1ll*frac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int l[Maxn+5],r[Maxn+5];
bool vis[Maxn+5];
int n,m;
int a[Maxm+5],b[Maxm+5];
int f[1<<Maxm|5][Maxm+5];
int lis[Maxm<<1|5],len;
bool in[Maxn+5],out[Maxn+5];
int deg[Maxn+5];
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],val[Maxn+5],tot;
int sum[Maxn+5];
void add_edge(int from,int to,int w){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	val[tot]=w;
	head[from]=tot;
}
bool build_graph(int mask){
	len=0;
	for(int i=1;i<=m;i++){
		if((mask>>(i-1))&1){
			if(!in[a[i]]){
				in[a[i]]=1;
				lis[++len]=a[i];
			}
			if(!in[b[i]]){
				in[b[i]]=1;
				lis[++len]=b[i];
			}
		}
	}
	tot=0;
	for(int i=1;i<=len;i++){
		head[lis[i]]=0;
		deg[lis[i]]=0;
	}
	for(int i=1;i<=m;i++){
		if(in[a[i]]&&in[b[i]]&&(mask>>(i-1)&1)==0){
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		if((mask>>(i-1))&1){
			deg[a[i]]++;
			deg[b[i]]++;
			add_edge(a[i],b[i],i);
			add_edge(b[i],a[i],i);
		}
	}
	return 1;
}
void connect_dfs(int u,int &mask){
	for(int i=head[u];i;i=nxt[i]){
		if(((1<<(val[i]-1))&mask)>0){
			continue;
		}
		mask|=(1<<(val[i]-1));
		int v=arrive[i];
		connect_dfs(v,mask);
	}
}
int calc(int mask){
	for(int i=1;i<=m;i++){
		if((mask>>(i-1))&1){
			out[a[i]]=out[b[i]]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=len;i++){
		if(in[lis[i]]&&!out[lis[i]]){
			ans++;
		}
	}
	for(int i=1;i<=m;i++){
		if((mask>>(i-1))&1){
			out[a[i]]=out[b[i]]=0;
		}
	}
	return ans;
}
bool check(int x,int len){
	return l[x]<=len&&len<=r[x];
}
int count(int x){
	int ans=0;
	while(x){
		ans++;
		x-=(x&(-x));
	}
	return ans;
}
int main(){
	init();
	read(n),read(m);
	for(int i=1;i<=n;i++){
		read(l[i]),read(r[i]);
	}
	for(int i=1;i<=m;i++){
		read(a[i]),read(b[i]);
		vis[a[i]]=vis[b[i]]=1;
	}
	for(int mask=0;mask<(1<<m);mask++){
		f[mask][0]=1;
		if(mask==0){
			continue;
		}
		if(!build_graph(mask)){
			for(int j=1;j<=len;j++){
				in[lis[j]]=0;
			}
			f[mask][0]=0;
			continue;
		}
		int nmask=0;
		connect_dfs(lis[1],nmask);
		if(nmask!=mask){
			for(int j=0;j<=m;j++){
				if(f[nmask][j]==0){
					continue;
				}
				for(int k=0;k+j<=m;k++){
					if(j==0&&k==0){
						continue;
					}
					f[mask][j+k]=(f[mask][j+k]+1ll*f[nmask][j]*f[mask^nmask][k])%Mod;
				}
			}
			for(int j=1;j<=len;j++){
				in[lis[j]]=0;
			}
			continue;
		}
		nmask=mask;
		int u=lis[1];
		int num=0;
		for(int j=head[u];j;j=nxt[j]){
			nmask&=(~(1<<(val[j]-1)));
		}
		num=calc(nmask)-1;
		for(int j=1;j<=m;j++){
			for(int k=0;k<=j;k++){
				f[mask][j]=(f[mask][j]+1ll*f[nmask][k]*C(num,j-k))%Mod;
			}
		}
		num=0;
		for(int j=head[u];j;j=nxt[j]){
			int v=arrive[j];
			for(int k=head[v];k;k=nxt[k]){
				nmask&=(~(1<<(val[k]-1)));
				if(arrive[k]==u){
					continue;
				}
			}
		}
		num=calc(nmask)-1-deg[lis[1]];
		for(int j=1;j<=m;j++){
			for(int k=0;k<j;k++){
				f[mask][j]=(f[mask][j]+1ll*f[nmask][k]*C(num,j-1-k))%Mod;
			}
		}
		for(int j=1;j<=len;j++){
			in[lis[j]]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			sum[l[i]]++;
			sum[r[i]+1]--;
		}
	}
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int mask=0;
		for(int j=1;j<=m;j++){
			if(check(a[j],i)&&check(b[j],i)){
				in[a[j]]=in[b[j]]=1;
				mask|=(1<<(j-1));
			}
		}
		int num=0;
		for(int j=1;j<=m;j++){
			if(check(a[j],i)&&!in[a[j]]){
				num++;
				in[a[j]]=1;
			}
			if(check(b[j],i)&&!in[b[j]]){
				num++;
				in[b[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			in[a[j]]=in[b[j]]=0;
		}
		for(int j=0;j<=m;j++){
			for(int k=0;k<=j;k++){
				ans=(ans+1ll*C(sum[i],i-j)*f[mask][k]%Mod*C(num,j-k))%Mod;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
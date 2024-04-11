#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5,maxm=2e4+5,maxc=8e3;
int n,m,C,q,ql[maxn],qr[maxn];
bool np[maxn];
vector<int> p;
int cnt=1,p1[maxc],p2[maxc],p3[maxc];
int sz[(1<<11)+5],lb[(1<<11)+5],f[(1<<11)+5][maxc];
int s[maxn][32];
vector<int> fac[maxn];
int S,ord[maxn],c[maxm],ans[maxn];
void FWT(int d){
	for(int i=0;i<11;i++)
		for(int j=0;j<(1<<11);j++)
			if(j>>i&1) f[j][d]+=f[j^(1<<i)][d];
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=max(read(),31ll);
	C=read();
	q=read();
	for(int i=2;i<=m;i++){
		if(!np[i]) p.push_back(i);
		for(int j:p){
			if(i*j>m) break;
			np[i*j]=1;
			if(i%j==0) break;
		}
	}
	p1[1]=p2[1]=p3[1]=1;
	for(int i=11;i<(int)p.size();i++){
		cnt++;
		p1[cnt]=p[i];
		p2[cnt]=p3[cnt]=1;
		for(int j=i+1;j<(int)p.size()&&p[i]*p[j]<=C;j++){
			cnt++;
			p1[cnt]=p[i];
			p2[cnt]=p[j];
			p3[cnt]=1;
			for(int k=j+1;k<(int)p.size()&&1ll*p[i]*p[j]*p[k]<=C;k++){
				cnt++;
				p1[cnt]=p[i];
				p2[cnt]=p[j];
				p3[cnt]=p[k];
			}
		}
	}
	for(int i=1;i<(1<<11);i++){
		sz[i]=sz[i>>1]+(i&1);
		lb[i]=i&1?0:lb[i>>1]+1;
	}
	for(int i=1;i<=cnt;i++){
		f[0][i]=C/p1[i]/p2[i]/p3[i];
		for(int j=1;j<(1<<11);j++)
			f[j][i]=f[j^(1<<lb[j])][i]/p[lb[j]];
		for(int j=0;j<(1<<11);j++)
			if((sz[j]%2==1)^(p1[i]>1)^(p2[i]>1)^(p3[i]>1)) f[j][i]*=-1;
		FWT(i);
	}
	for(int i=1;i<=n;i++){
		int a=read();
		for(int j=0;j<11;j++) s[i][p[j]]=s[i-1][p[j]];
		for(int j=0;p[j]*p[j]<=a;j++) if(a%p[j]==0){
			while(a%p[j]==0) a/=p[j];
			if(j<11) s[i][p[j]]++;
			else fac[i].push_back(p[j]);
		}
		if(a>1){
			if(a<=31) s[i][a]++;
			else fac[i].push_back(a);
		}
	}
	for(int i=1;i<=q;i++){
		ql[i]=read();
		qr[i]=read();
	}
	S=sqrt(n);
	for(int i=1;i<=q;i++) ord[i]=i;
	sort(ord+1,ord+q+1,[](int a,int b){
		if(qr[a]/S!=qr[b]/S) return qr[a]<qr[b];
		return ql[a]<ql[b];
	});
	int l=1,r=0;
	c[1]=1;
	for(int i=1;i<=q;i++){
		int u=ord[i];
		while(l>ql[u]){
			l--;
			for(int j:fac[l]) c[j]++;
		}
		while(r<qr[u]){
			r++;
			for(int j:fac[r]) c[j]++;
		}
		while(l<ql[u]){
			for(int j:fac[l]) c[j]--;
			l++;
		}
		while(r>qr[u]){
			for(int j:fac[r]) c[j]--;
			r--;
		}
		int b=0;
		for(int j=0;j<11;j++)
			if(s[r][p[j]]>s[l-1][p[j]]) b|=1<<j;
		for(int j=1;j<=cnt;j++)
			if(c[p1[j]]&&c[p2[j]]&&c[p3[j]]) ans[u]+=f[b][j];
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}
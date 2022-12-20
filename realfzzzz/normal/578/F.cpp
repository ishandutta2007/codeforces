#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=100+5,maxk=200+5;
int n,m;
ll p;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2==1) ans=ans*a%p;
		a=a*a%p;
		b/=2;
	}
	return ans;
}
char s[maxn][maxn];
int fa[maxn*maxn];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
int k1=0,k2=0,no[maxn*maxn];
ll a[maxk*2][maxk*2];
void add_edge(int u,int v){
	a[u][u]++;
	a[v][v]++;
	a[u][v]=(a[u][v]-1+p)%p;
	a[v][u]=(a[v][u]-1+p)%p;
}
ll det(int n){
	ll ans=1;
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++) if(a[j][i]){
			swap(a[i],a[j]);
			if(i!=j) ans=(p-ans)%p;
			break;
		}
		if(!a[i][i]) return 0;
		ans=ans*a[i][i]%p;
		for(int j=i+1;j<n;j++){
			ll t=a[j][i]*ksm(a[i][i],p-2)%p;
			for(int k=i;k<n;k++)
				a[j][k]=(a[j][k]-a[i][k]*t%p+p)%p;
		}
	}
	return ans;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=read();
	m=read();
	p=read();
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=(m+1)*(n+1);i++) fa[i]=i;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		if(s[i][j]!='*'){
			int u,v;
			if(s[i][j]=='/'){
				u=(m+1)*(i-1)+j+1;
				v=(m+1)*i+j;
			}
			else{
				u=(m+1)*(i-1)+j;
				v=(m+1)*i+j+1;
			}
			if(find(u)==find(v)){
				printf("0\n");
				return 0;
			}
			fa[fa[u]]=v;
		}
	for(int i=0;i<=n;i++) for(int j=1;j<=m+1;j++){
		int u=(m+1)*i+j;
		if(find(u)==u) no[u]=(i+j)%2==0?k1++:k2++;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='*'){
		if((i+j)%2==0)
			add_edge(no[find((m+1)*(i-1)+j+1)],no[find((m+1)*i+j)]);
		else if((i+j)%2==1)
			add_edge(no[find((m+1)*(i-1)+j)],no[find((m+1)*i+j+1)]);
	}
	ll res=det(k1);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='*'){
		if((i+j)%2==0)
			add_edge(no[find((m+1)*(i-1)+j)],no[find((m+1)*i+j+1)]);
		else if((i+j)%2==1)
			add_edge(no[find((m+1)*(i-1)+j+1)],no[find((m+1)*i+j)]);
	}
	printf("%lld\n",(res+det(k2))%p);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}
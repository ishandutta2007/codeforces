#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
namespace Mymath{
	LL qp(LL x,LL p,LL mod){
		LL ans=1;
		while (p){
			if (p&1) ans=ans*x%mod;
			x=x*x%mod;
			p>>=1;
		}
		return ans;
	}
	LL inv(LL x,LL mod){
		return qp(x,mod-2,mod);
	}
	LL C(LL N,LL K,LL fact[],LL mod){
		return fact[N]*inv(fact[K],mod)%mod*inv(fact[N-K],mod)%mod;
	}
	template <typename Tp> Tp gcd(Tp A,Tp B){
		if (B==0) return A;
		return gcd(B,A%B);
	}
	template <typename Tp> Tp lcm(Tp A,Tp B){
		return A*B/gcd(A,B);
	}
};
namespace fwt{
	using namespace Mymath;
	void FWT(int a[],int n,LL mod)
	{
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
	                //xor:a[i+j]=x+y,a[i+j+d]=x-y;
	                //and:a[i+j]=x+y;
	                //or:a[i+j+d]=x+y;
	            }
	}

	void UFWT(int a[],int n,LL mod)
	{
		LL rev=inv(2,mod);
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
	                //xor:a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
	                //and:a[i+j]=x-y;
	                //or:a[i+j+d]=y-x;
	            }
	}
	void solve(int a[],int b[],int n,LL mod)
	{
	    FWT(a,n,mod);
	    FWT(b,n,mod);
	    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%mod;
	    UFWT(a,n,mod);
	}
};
const int Maxn=1e6+5;
vector<int > G[Maxn];
int tp[Maxn];
int n;
int ans[Maxn];
char buf[6];
bool aff[Maxn];
void dfs(int x){
	if (!tp[x]) return;
	if (tp[x]==4){
		dfs(G[x][0]);
		ans[x]=ans[G[x][0]]^1;
	}
	else if (tp[x]==1){
		dfs(G[x][0]);
		dfs(G[x][1]);
		ans[x]=ans[G[x][0]]&ans[G[x][1]];
	}
	else if (tp[x]==2){
		dfs(G[x][0]);
		dfs(G[x][1]);
		ans[x]=ans[G[x][0]]|ans[G[x][1]];
	}
	else if (tp[x]==3){
		dfs(G[x][0]);
		dfs(G[x][1]);
		ans[x]=ans[G[x][0]]^ans[G[x][1]];
	}
}
void dfs2(int x){
	//cout<<x<<endl;
	if (!tp[x]) return;
	if (tp[x]==4){
		aff[G[x][0]]=1;
		dfs2(G[x][0]);
		return;
	}
	if (tp[x]==1){
		int u=G[x][0],v=G[x][1];
		if ((ans[u]&ans[v])!=(ans[u]&(ans[v]^1))){
			aff[v]=true;
			dfs2(v);
		}
		if ((ans[u]&ans[v])!=((ans[u]^1)&(ans[v]))){
			aff[u]=true;
			dfs2(u);
		}
		return;
	}
	if (tp[x]==2){
		int u=G[x][0],v=G[x][1];
		if ((ans[u]|ans[v])!=(ans[u]|(ans[v]^1))){
			aff[v]=true;
			dfs2(v);
		}
		if ((ans[u]|ans[v])!=((ans[u]^1)|(ans[v]))){
			aff[u]=true;
			dfs2(u);
		}
		return;
	}
	if (tp[x]==3){
		int u=G[x][0],v=G[x][1];
		if ((ans[u]^ans[v])!=(ans[u]^(ans[v]^1))){
			aff[v]=true;
			dfs2(v);
		}
		if ((ans[u]^ans[v])!=((ans[u]^1)^(ans[v]))){
			aff[u]=true;
			dfs2(u);
		}
		return;
	}
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		scanf("%s",buf);
		if (buf[0]=='I'){
			int v=read();
			ans[i]=v;
		}
		else if (buf[0]=='A'){
			int u=read(),v=read();
			G[i].pb(u);G[i].pb(v);
			tp[i]=1;
		}
		else if (buf[0]=='O'){
			int u=read(),v=read();
			G[i].pb(u);G[i].pb(v);
			tp[i]=2;
		}
		else if (buf[0]=='X'){
			int u=read(),v=read();
			G[i].pb(u);G[i].pb(v);
			tp[i]=3;
		}
		else{
			int u=read();
			G[i].pb(u);tp[i]=4;
		}
	}
	dfs(1);
	//cout<<ans[1]<<endl;
	aff[1]=1;
	dfs2(1);
	string res;
	for (int i=1;i<=n;i++){
		if (!tp[i]){
			res+=(char)((ans[1]^aff[i])+'0');
		}
	}
	printf("%s\n",res.c_str());
	return 0;
}
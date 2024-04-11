#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=1e5+9;
const int mod=1e9+7;
inline int add(int a,const int &b){
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}
inline int sub(int a,const int &b){
	a-=b;
	if(a<0)a+=mod;
	return a;
}
inline int mul(const int &a,const int &b){return 1ll*a*b%mod;}
int jie[N],inv[N];
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
inline int C(int m,int n){
	if(n>m||m<0||n<0)return 0;
	return mul(mul(jie[m],inv[n]),inv[m-n]);
}
void pre(){
	inv[0]=inv[1]=1,jie[0]=1;
	rep(i,2,N)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N)inv[i]=mul(inv[i],inv[i-1]),jie[i]=mul(jie[i-1],i);
}
int SL[2][N],SR[2][N],SD[N],D[N],G[2][N];
int main(){
	pre();
	int n,m,a,b,P,k;
	int c=0;
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&k);
	P=mul(a,quick(b,mod-2));
	rep(i,0,k+1)D[i]=mul(C(k,i),mul(quick(P,i),quick(sub(1,P),k-i)));
//	cout<<D[0]<<"check\n";
	SD[0]=D[0];
	rep(i,1,m+1)SD[i]=add(SD[i-1],D[i]);
	SL[0][m]=SR[0][1]=1;
	rep(i,1,n+1){
		G[c][0]=mul(D[0],SL[c][0]);
		rep(r,1,m+1)G[c][r]=add(G[c][r-1],mul(D[r],SL[c][r]));
		c^=1;
		rep(r,1,m+1)SL[c][r]=mul(D[m-r],sub(mul(sub(SL[c^1][m],SR[c^1][r+1]),SD[r-1]),G[c^1][r-1]));
		rep(r,1,m+1)SL[c][r]=add(SL[c][r],SL[c][r-1]);
		rep(r,1,m+1)SR[c][r]=SL[c][m+1-r];
	}
	printf("%d\n",SL[c][m]);
}
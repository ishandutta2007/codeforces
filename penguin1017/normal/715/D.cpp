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
const int N=1<<21;
const ll mod=998244353;
const ll Inf=1e18;
/*
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
*/
struct node{
	int a,b,c,d;
	node(int a=0,int b=0,int c=0,int d=0):a(a),b(b),c(c),d(d){}
	void out(){
		printf("%d %d %d %d\n",a,b,c,d);
	}
} p[300];
int cnt;
void add(int i,int x){
	p[cnt++]=node(i-1,i+1,i,i+1);
	if(x<3)p[cnt++]=node(i+1,i-1,i+1,i);
	else x-=3;
	if(x<2)p[cnt++]=node(i+2,i-1,i+2,i);
	else --x;
	if(!x)p[cnt++]=node(i-1,i+2,i,i+2);
}
int main(){
	//pre();
	ll n;
	scanf("%lld",&n);
	for(int i=1;i<=45;i+=2){
		p[cnt++]=node(i,i+4,i,i+5);
		p[cnt++]=node(i+4,i,i+5,i);
		p[cnt++]=node(i+1,i+4,i+1,i+5);
		p[cnt++]=node(i+4,i+1,i+5,i+1);
		p[cnt++]=node(i+1,i+3,i+1,i+4);
		p[cnt++]=node(i+3,i+1,i+4,i+1);
		p[cnt++]=node(i+2,i+3,i+2,i+4);
		p[cnt++]=node(i+3,i+2,i+4,i+2);
	}
	p[cnt++]=node(1,2,2,2);
	p[cnt++]=node(2,1,2,2);
	for(int i=48;i>=2;i-=2){
		add(i,n%6);
		n/=6;
	}
	printf("50 50\n%d\n",cnt);
	rep(i,0,cnt)p[i].out();
}
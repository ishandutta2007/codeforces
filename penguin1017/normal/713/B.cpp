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
int check(int x1,int y1,int x2,int y2){
	cout.flush()<<"? "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
	int x;
	scanf("%d",&x);
	return x;
}
int main(){
	int n;
	scanf("%d",&n);
	int x1=1,x2=n,x3=1,x4=n,y1=1,y2=n,y3=1,y4=n;
	int l=1,r=n;
	while(l<r){
		int m=l+r>>1;
		if(!check(x1,y1,m,y2))l=m+1;
		else r=m;
	}
//	cout<<"ok\n";
	x2=l;
	l=1,r=x2+1;
	while(l<r){
		int m=l+r>>1;
		if(!check(m,y1,x2,y2))r=m;
		else l=m+1;
	}
	x1=l-1;
	l=1,r=n;
//	cout<<"ok2\n";
	while(l<r){
		int m=l+r>>1;
		if(!check(x1,y1,x2,m))l=m+1;
		else r=m;
	}
	y2=l;
	l=1,r=y2+1;
	while(l<r){
		int m=l+r>>1;
		if(!check(x1,m,x2,y2))r=m;
		else l=m+1;
	}
	y1=l-1;
	
	l=1,r=n+1;
	while(l<r){
		int m=l+r>>1;
		int val=(m<=x1&&x2<=x4&&y3<=y1&&y2<=y4);
		if(!(check(m,y3,x4,y4)-val))r=m;
		else l=m+1;
	}
	x3=l-1;
	l=x3,r=n;
	while(l<r){
		int m=l+r>>1;
		int val=(x3<=x1&&x2<=m&&y3<=y1&&y2<=y4);
		if(!(check(x3,y3,m,y4)-val))l=m+1;
		else r=m;
	}
	x4=l;
	l=1,r=n+1;
	while(l<r){
		int m=l+r>>1;
		int val=(x3<=x1&&x2<=x4&&m<=y1&&y2<=y4);
		if(!(check(x3,m,x4,y4)-val))r=m;
		else l=m+1;
	}
	y3=l-1;
	l=y3,r=n;
	while(l<r){
		int m=l+r>>1;
		int val=(x3<=x1&&x2<=x4&&y3<=y1&&y2<=m);
		if(!(check(x3,y3,x4,m)-val))l=m+1;
		else r=m;
	}
	y4=l;
	printf("! %d %d %d %d %d %d %d %d",x1,y1,x2,y2,x3,y3,x4,y4);
	fflush(stdout);
}
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int main(){
	ll u,v;
	scanf("%lld%lld",&u,&v);
	if((u^v)&1){
		cout<<-1;
		return 0;
	}
	if(u==0&&v==0){
		cout<<0;
		return 0; 
	}
	if(u>v){
		cout<<-1;
		return 0;
	}
	if(u==v){
		cout<<1<<endl<<u;
		return 0;
	}
	ll x=0,y=0,w=(v-u)>>1;
	int flag=1;
	rep(i,0,61){
		ll op=1ll<<i;
		if(u&op){
			if(w&op)flag=0;
			else x^=op;
		}
		else{
			if(w&op)x^=op,y^=op;
		}
	}
	
	if(flag){
		cout<<2<<endl<<x<<' '<<y;
		return 0;
	}
	cout<<3<<endl;
	x=u,y=(v-u)/2;
	cout<<x<<' '<<y<<' '<<y;
}
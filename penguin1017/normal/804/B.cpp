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
using namespace std;
const int N=2e6+9;
const ll mod=1e9+7;
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
char s[N];
int main(){
	int n;
	scanf("%s",s);
	n=strlen(s);
	ll res=0,num=0;
	rep(i,0,n){
		if(s[i]=='a')num=(num+1)%(mod-1);
		else{
			res=(res+quick(2,num)+mod-1)%mod;
		}
	}
	cout<<res; 
}
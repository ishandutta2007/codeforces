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
const int N=2e6+9;
const ll mod=998244353;
const ll Inf=1e18;
char s[11]={'c','o','d','e','f','o','r','c','e','s'};
int main(){
	ll n,i,sum=1,a=0,b=10;
	cin>>n;
	if(n==1){
		cout<<"codeforces";
		return 0;
	}
	for(i=2;i<=50;++i){
		for(a=1,b=9;a<=10;a++,b--){
			sum=sum/(i-1)*i;
			if(sum>=n)break;
		}
		if(a<=10)break;
	}
	rep(k,0,a){
		rep(j,0,i)printf("%c",s[k]);
	}
	rep(k,a,10){
		rep(j,1,i)printf("%c",s[k]);
	}
}
/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
char s[200005];
void solve(){
	int n;
	scanf("%s",s+1);
	n=strlen(s+1);
	int sum1=0,sum2=0,ans=0;
	FOR(i,1,n){
		char c=s[i];
		if(c=='('){
			sum1++;
		}else if(c==')'){
			if(sum1){
				ans++;
				sum1--;
			}
		}else if(c=='['){
			sum2++;
		}else{
			if(sum2){
				ans++;
				sum2--;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	RE 0;
}
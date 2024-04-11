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
int n;
char c[105];
void solve(){
	scanf("%d%s",&n,c+1);
	int l=0;
	for(int i=n;i>=1;i--){
		if(c[i]!=')'){
			l=i;break;
		}
	}
	if(l<n-l){
	cout<<"Yes\n";
	}else cout<<"No\n";
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int t;scanf("%d",&t);
	while(t--)solve(); 
	RE 0;
}
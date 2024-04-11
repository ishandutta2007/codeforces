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
char c[200005];
void solve(){
	scanf("%s",c+1);
	int cnt[3]={};
	string s="PRS";
	int t=strlen(c+1);
	FOR(i,1,t){
		if(c[i]=='R'){
			cnt[0]++;
		}else if(c[i]=='S'){
			cnt[1]++;
		}else cnt[2]++;
	}
	int it;
	if(cnt[0]>=cnt[1]&&cnt[0]>=cnt[2]){
		it=0;
	}else if(cnt[1]>=cnt[0]&&cnt[1]>=cnt[2]){
		it=1;
	}else it=2;
	FOR(i,1,t)cout<<s[it];
	cout<<'\n';
}
signed main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	RE 0;
}
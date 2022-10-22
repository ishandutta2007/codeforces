#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
string s;
int n,t[26];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	int ans=0;
	rep(i,0,s.size()){
		t[s[i]-'a']++;
	}
	FOR(i,0,25){
		ans=max(ans,t[i]);
	}
	char c1,c2;
	int cnt,ant;
	FOR(i,0,25){
		FOR(j,0,25){
			c1=i+'a';
			c2=j+'a';
			cnt=ant=0;
			rep(k,0,s.size()){
				if(s[k]==c1){
					ant+=cnt;
				}
				if(s[k]==c2){
					cnt++;
				}
			} 
			ans=max(ans,ant);
		}
	}
	cout<<ans;
	RE 0;
}
#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
char c[200005];
int cnt[26];
void solve(){
	string s;
	cin>>s;
	int n=s.size();
	FOR(i,1,n)c[i]=s[i-1];
	FILL(cnt,0);
	FOR(i,1,n){
		cnt[c[i]-'a']++;
	}
	int it=1;
	FOR(i,1,n){
		if(cnt[c[i]-'a']==1){
			it=i;break;
		}else cnt[c[i]-'a']--;
	}
	FOR(i,it,n)cout<<c[i];
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}
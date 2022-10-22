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
int cnt[4],a[200005];
string s;
void solve(){
	cin>>s;
	int n=s.size();
	FOR(i,1,n){
		a[i]=s[i-1]-'0';
	}
	int l=1,ans=1e9;
	FILL(cnt,0);
	FOR(i,1,n){
		cnt[a[i]]++;
		while(l<i&&cnt[a[l]]>1){
			cnt[a[l]]--;l++;
		}
		bool f=1;
		FOR(j,1,3){
			if(!cnt[j]){
				f=0;break;
			}
		}
		if(f)gmin(ans,i-l+1);
	}
	if(ans<=n)cout<<ans<<'\n';else cout<<"0\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}
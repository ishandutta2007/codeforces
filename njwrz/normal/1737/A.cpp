#include<bits/stdc++.h>
#define int long long
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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int cnt[26],n,k;
void solve(){
	cin>>n>>k;
	FILL(cnt,0);
	rep(i,0,n){
		char c;
		cin>>c;
		cnt[c-'a']++;
	}
	rep(i,0,k){
		int t=-1;
		rep(j,0,min(26ll,n/k))if(!cnt[j]){
			t=j;break;
		}else cnt[j]--;
		if(t==-1)t=n/k;
		cout<<(char)(t+'a');
	}
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
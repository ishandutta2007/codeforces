#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int maxn=200007;
const int mod=1e9+7;
const int inf=LLONG_MAX/4;
mt19937 rng(time(NULL)); // don't hack, pls!
int n;
int a[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
	int _;
	cin>>_;
	while (_--){
		cin>>n;
		int cnt[2]={0,0};
		int ans=0,t1=0,t2=0;
		vi res;
		res.clear();
		rep(i,n) cin>>a[i];
		rep(i,n) cnt[a[i]&1]++;
		if (abs(cnt[1]-cnt[0])>1){
			cout<<-1<<"\n";
			goto cont;
		}
		if (n&1){
			if (cnt[0]>cnt[1]){
				rep(i,n){
					if (a[i]%2==0) res.pb(i);
				}
			}
			else{
				rep(i,n){
					if (a[i]&1) res.pb(i);
				}
			}
			rep(i,n/2+1){
				ans+=abs(res[i]-2*i);	
			}
		}
		else{
			rep(i,n) if (a[i]%2==0) res.pb(i);
			rep(i,n/2) t1+=abs(res[i]-2*i);
			res.clear();
			rep(i,n) if (a[i]&1) res.pb(i);
			rep(i,n/2) t2+=abs(res[i]-2*i);
			ans=min(t1,t2);
		}
		cout<<ans<<"\n";
		
		cont:;
	}
	return 0;
}
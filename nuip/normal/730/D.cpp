#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const ll MOD = 1e9+7;

ll l[200005], t[200005];
int main(){
	ll N, r;
	cin >> N >> r;
	rep(i,N) cin >> l[i];
	rep(i,N) cin >> t[i];

	rep(i,N){
		if( t[i] < l[i] ){
			cout << -1 << endl;
			return 0;
		}
	}

	ll ans=0, c=0;
	ll sum[200005]={};
	vector<ll> ks;
	rep(i,N){
		ll up = min(c, l[i]);
		if( up == l[i] ){
			c -= up;
			sum[i+1] = sum[i] + up;
			continue;
		}
		ll limit = l[i]*2 - up - t[i];
		ll tmp = 0, up2=0;
		if( limit > 0 ){
			tmp = limit/r + (limit%r ? 1 : 0);
			ans += tmp;
			c = r - (limit%r==0 ? r : limit%r);
			up2 = tmp*r - c;
		}else{
			c -= up;
		}
		sum[i+1] = sum[i] + min( max( l[i], l[i]*2 - up - up2), t[i]);
		{
			ll now = sum[i] + up;
			while( (int)ks.size() < 1e5 && tmp ){
				if( tmp > 1 ){
					ks.pb(now);
					now += r;
				}else{
					ks.pb( sum[i+1] - (limit%r==0 ? r : limit%r) );
				}
				tmp--;
			}
		}
	}

	cout << ans << endl;
	if( ans <= 1e5 ){
		for(auto t: ks) cout << t << " "; cout << endl;
	}

	return 0;
}
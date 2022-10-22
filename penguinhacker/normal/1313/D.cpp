#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define debug(x) cerr << '[' << #x << "] = " << (x) << '\n';

const int mxN=100000;
int n, m, k, dp[1<<8], nxt[1<<8];
ar<int, 2> p[mxN];
ar<int, 3> e[2*mxN]; //events
vector<int> cur;

void pr(int x) {
	for (int i=30; ~i; --i)
		cout << ((x&(1<<i))?1:0);
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k, k=0;
	for (int i=0; i<n; ++i) {
		cin >> p[i][0] >> p[i][1];
		e[2*i]={p[i][0], 0, i};
		e[2*i+1]={p[i][1], 1, i};
	}
	sort(e, e+2*n);
	auto move_up=[&](int mask, int pos) {
		return ( (mask&((1<<pos)-1))|((mask&(((1<<10)-1)<<pos))<<1) );
	};
	auto move_down=[&](int mask, int pos) {
		return ( (mask&((1<<pos)-1))|((mask&(((1<<10)-1)<<(pos+1)))>>1) );
	};
	auto calc=[&](int mask, int ind) {
		vector<int> v;
		for (int i=0; i<cur.size(); ++i) if (mask&(1<<i)) {
			v.push_back(min(p[ind][1], p[cur[i]][1]));
		}
		sort(v.rbegin(), v.rend());
		int res=0;
		for (int i=0; i<v.size(); ++i)
			res+=(v[i]-p[ind][0]+1)*((i&1)?-1:1);
		res=(p[ind][1]-p[ind][0]+1-res)-res;
		//res+=(v.back()-p[ind][0]+1)*(((int)(v.size()-1)&1)?-1:1);
		//cout << mask << ' ' << ind << ' ' << res << '\n';
		return res;
	};
	for (int ev=0; ev<2*n; ++ev) {
		int ind=e[ev][2];
		memset(nxt, 0, sizeof(nxt));
		if (e[ev][1]==0) {
			auto it=lower_bound(cur.begin(), cur.end(), ind);
			int pos=it-cur.begin();
			//debug(pos);
			cur.insert(it, ind);
			for (int i=0; i<(1<<k); ++i) {
				int nm=move_up(i, pos); //next mask
				//if (ev==1) cout << "               " <<  i << ' ' << nm << '\n';
				nxt[nm]=max(nxt[nm], dp[i]);
				nxt[nm|(1<<pos)]=max(nxt[nm|(1<<pos)], dp[i]+calc(nm, ind));
			}
			++k;
		}
		else {
			int pos=lower_bound(cur.begin(), cur.end(), ind)-cur.begin();
			for (int i=0; i<(1<<k); ++i) {
				int nm=move_down(i, pos);
				nxt[nm]=max(nxt[nm], dp[i]);
			}
			cur.erase(cur.begin()+pos);
			--k;
		}
		for (int i=0; i<(1<<k); ++i) {
			dp[i]=nxt[i];
			//cout << dp[i] << ' ';
		}
		//cout << "\n";
	}
	//pr(move_up(31, 2));
	int ans=0;
	for (int i=0; i<(1<<k); ++i)
		ans=max(ans, dp[i]);
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
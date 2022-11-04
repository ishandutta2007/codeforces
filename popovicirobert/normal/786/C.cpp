#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MAXN = (int) 1e5;
const int LIM = 500;

int fr[MAXN / LIM + 1][MAXN + 1];

struct Segm {
	int l, r;
	int cnt;
};

int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector<int> arr(n + 1), last(n + 1), prv(n + 1);
    vector<vector<int>> ids(n + 1);
    for(i = 1; i <= n; i++) {
    	cin >> arr[i];
    	prv[i] = last[arr[i]];
    	ids[prv[i]].push_back(i);
    	last[arr[i]] = i;
    }

  	for(int k = 1; k <= LIM && k <= n; k++) {
  		int ans = 0;
  		i = 1;
  		while(i <= n) {
  			int j = i, cnt = 0;
  			while(j <= n && cnt + (prv[j] < i) <= k) {
  				cnt += (prv[j] < i);
  				j++;
  			}
  			ans++;
  			i = j;
  		}
  		cout << ans << " ";
  	}

  	vector<Segm> segm(n / LIM + 1, {1, 0, 0});
  	for(int k = LIM + 1; k <= n; k++) {
  		int last = 0, sz = 0;
  		for(auto& it : segm) {
  			while(it.l <= it.r && it.l <= last) {
  				fr[sz][arr[it.l]]--;
  				it.cnt -= (fr[sz][arr[it.l]] == 0);
  				it.l++;
  			}
  			it.l = last + 1;
  			it.r = max(it.r, it.l - 1);
  			while(it.r < n && it.cnt + (fr[sz][arr[it.r + 1]] == 0) <= k) {
  				it.r++;
  				it.cnt += (fr[sz][arr[it.r]] == 0);
  				fr[sz][arr[it.r]]++;
  			}
  			sz++;
  			last = it.r;
  			if(last == n) {
  				break;
  			}
  		}
  		cout << sz << " ";
  	}
    
    return 0;
}
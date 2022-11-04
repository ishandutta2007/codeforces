#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;



int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
    	int h, g; cin >> h >> g;
    	vector<int> arr((1 << h) - 1);
    	for(i = 0; i < (1 << h) - 1; i++) {
    		cin >> arr[i];
    	}
    	vector<vector<int>> mst((1 << h) - 1);
    	vector<int> sol((1 << h) - 1);
    	for(i = (1 << h) - 2; i >= 0; i--) {
    		if(2 * i + 1 < (1 << h) - 1) {
    			int a = 2 * i + 1, b = 2 * i + 2;

    			int sza = mst[a].size(), szb = mst[b].size();
    			int pa = 0, pb = 0;
    			while(pa < sza && pb < szb) {
    				if(mst[a][pa] < mst[b][pb]) {
    					mst[i].push_back(mst[a][pa++]);
    				}
    				else {
    					mst[i].push_back(mst[b][pb++]);
    				}
    			}
    			while(pa < sza) {
    				mst[i].push_back(mst[a][pa++]);
    			}
    			while(pb < szb) {
    				mst[i].push_back(mst[b][pb++]);
    			}
    			mst[a].clear(), mst[b].clear();

    			mst[i].push_back(0);
    			int p = sza + szb - 1;
    			while(mst[i][p] > arr[i]) {
    				swap(mst[i][p], mst[i][p + 1]);
    				p--;
    			}
    			mst[i][p + 1] = arr[i];
    		}
    		else {
    			mst[i].push_back(arr[i]);
    		}
    	
    		if(i < (1 << g) - 1) {
    			int mx = 0;
    			if(2 * i + 1 < (1 << h) - 1) {
    				mx = max(sol[2 * i + 1], sol[2 * i + 2]);
    			}
    			int p = 0;
    			while(mst[i][p] < mx) {
    				p++;
    			}
    			sol[i] = mst[i][p];
    			while(p + 1 < (int)mst[i].size()) {
    				mst[i][p] = mst[i][p + 1];
    				p++;
    			}
    			mst[i].pop_back();
    		}
    	}

    	ll ans = 0;
    	for(i = 0; i < (1 << g) - 1; i++) {
    		ans += sol[i];
    	}
    	cout << ans << "\n";

    	function <void(int)> f = [&](int nod) {
    		int l = 2 * nod + 1, r = 2 * nod + 2;
    		if(l >= (1 << h) - 1 || (arr[l] == 0 && arr[r] == 0)) {
    			arr[nod] = 0;
    		}
    		else if(arr[l] > arr[r]) {
    			swap(arr[nod], arr[l]);
    			f(l);
    		}
    		else {
    			swap(arr[nod], arr[r]);
    			f(r);
    		}
    	};

    	function <void(int)> dfs = [&](int nod) {
    		if(nod >= (1 << g) - 1 || arr[nod] == 0) return ;

    		//cerr << nod << " " << arr[nod] << "\n";

    		while(arr[nod] != sol[nod]) {
    			f(nod);
    			cout << nod + 1 << " ";
    		}

    		dfs(2 * nod + 1);
    		dfs(2 * nod + 2);
    	};

    	dfs(0);

    	cout << "\n";
    }

    return 0;
}
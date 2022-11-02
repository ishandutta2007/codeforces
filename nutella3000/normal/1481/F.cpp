#include <bits/stdc++.h>
 
using namespace std;
 
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
  
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
 
const int inf = 1e9 + 7;
const int max_n = 1e5 + 3;

int dist[max_n];
vector<int> gr[max_n];

vector<int> f(int n, vector<vector<int>> a) {
	vector<int> id(n + 1, -1);
	id[0] = 0;
	int num = -1;
	for(auto b : a) {
		num++;
		if (!sz(b)) continue;
		vector<int> cnt(n + 1, -1);
		for(int i = 0;i <= n;i++)
			if (id[i] != -1) cnt[i] = 0;

		for(int i = num;i <= n;i++) {
			if (cnt[i] != 0 && cnt[i - num] != -1 && cnt[i - num] < sz(b)) cnt[i] = cnt[i - num] + 1;
		}
		for(int i = 0;i <= n;i++) {
			if (cnt[i] > 0) {
				id[i] = b[cnt[i] - 1];
			}
		}
	}
	return id;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n, cnt[2];
    cin >> n >> cnt[0];
    cnt[1] = n - cnt[0];
    for(int i = 1;i < n;i++) {
    	int v;
    	cin >> v;
    	gr[--v].emplace_back(i);
    }

    vector<int> r(n);
    deque<int> bfs;
    int lst = -1;
    {
    	bfs.emplace_back(0);
    	vector<vector<int>> a1;

    	while(!bfs.empty()) {
    		int v = bfs.front();
    		if (lst != dist[v]) {
    			vector<int> tmp;
    			for(int i : bfs)
    				tmp.emplace_back(i);
    			a1.emplace_back(tmp);
    		}
    		bfs.pop_front();
    		for(int to : gr[v])
    			bfs.emplace_back(to), dist[to] = dist[v] + 1;
    		lst = dist[v];
    	}

    	vector<vector<int>> a2(n + 1);
    	for(int i = 0;i < sz(a1);i++) { 
    		a2[sz(a1[i])].emplace_back(i);
    	}

    	vector<int> id = f(cnt[0], a2);

    	if (id[cnt[0]] != -1) {
    		cout << lst + 1 << endl;

    		fill(all(r), 1);
    		int num = cnt[0];
    		while(num > 0) {
    			for(int i : a1[id[num]]) {
    				r[i] = 0;
    			}
    			num -= sz(a1[id[num]]);
    		}
    		for(int i : r)
    			cout << (char) ('a' + i);
    		return 0;
    	}

    }


    bfs.clear();
    bfs.emplace_back(0);
    lst = -1;
    while(!bfs.empty()) {
    	int v = bfs.front();

    	if (dist[v] != lst) {
    		//vector<int> b;
    		sort(all(bfs), [](int v1, int v2) {
    			return sz(gr[v1]) > sz(gr[v2]);
    		});

    		bool bad = true;
    		for(int i = 0;i < 2;i++) {
    			if (cnt[i] >= sz(bfs)) {
    				for(int j : bfs)
    					r[j] = i;
    				cnt[i] -= sz(bfs);
    				bad = false;
    				break;
    			}
    		}

    		if (bad) {
	    		int big = (cnt[0] < cnt[1]);
	    		for(int i : bfs) {
	    			if (cnt[big]) {
	    				r[i] = big;
	    				cnt[big]--;
	    			}else {
	    				cnt[1 - big]--;
	    				r[i] = 1 - big;
	    			}
	    		}
    		}
    		//cout << cnt[0] << " " << cnt[1] << endl;
    	}
    	v = bfs.front();
    	bfs.pop_front();

    	for(int to : gr[v]) {
    		bfs.emplace_back(to);
    	}
    	lst = dist[v];
    }

    cout << lst + 2 << endl;
    for(int i : r)
    	cout << (char) ('a' + i);
    cout << endl;
}
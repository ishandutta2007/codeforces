#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);	

    int t;
   	cin >> t;
   	while (t--) {
   		int n, m;
   		cin >> n >> m;

   		vector<vector<pair<int, int>>> friends(m);
   		for (int i = 0; i < m; i++) {
   			int sz;
   			cin >> sz;
   			friends[i].resize(sz);
   			for (auto& it : friends[i]) {
   				cin >> it.first;
   				it.second = i;
   			}
   		}

   		 // 1 * 3
   		 // 2 * 3
   		 // 1, 2, 3
   		 // 1, 2, 3
   		 // 1, 2, 3

   		sort(friends.begin(), friends.end(), [](const auto& a, const auto& b) {
   			return a.size() < b.size();
   		});

   		vector<int> freq(n + 1), sol(m);
   		for (auto v : friends) {
   			int id = v[0].first;
   			for (auto it : v) {
   				if (freq[id] > freq[it.first]) {
   					id = it.first;
   				}
   			}
   			freq[id]++;
   			sol[v[0].second] = id;
   		}

   		if (*max_element(freq.begin(), freq.end()) > (m + 1) / 2) {
   			cout << "NO\n";
   		} else {
   			cout << "YES\n";
   			for (auto it : sol) {
   				cout << it << " ";
   			}
   			cout << "\n";
   		}
   	}


    return 0;
}
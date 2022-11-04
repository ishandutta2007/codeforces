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
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> t;
   	while(t--) {
   		int n;
   		cin >> n;

   		vector<vector<int>> pos(n + 1);
   		for(i = 0; i < n; i++) {
   			int x;
   			cin >> x;
   			pos[x].push_back(i + 1);
   		}

   		vector<int> sol(n + 2, n + 1);
   		for(i = 1; i <= n; i++) {
   			if(pos[i].empty()) continue;
   			int cur = pos[i][0] - 1;
   			for(int j = 1; j < (int)pos[i].size(); j++) {
   				cur = max(cur, pos[i][j] - pos[i][j - 1] - 1);
   			}
   			cur = max(cur, n - pos[i].back());
   			sol[cur + 1] = min(sol[cur + 1], i);
   		}
   		for(i = 1; i <= n; i++) {
   			sol[i] = min(sol[i], sol[i - 1]);
   			cout << (sol[i] == n + 1 ? -1 : sol[i]) << " ";
   		}
   		cout << "\n";
   	}
    
 
    return 0;
}
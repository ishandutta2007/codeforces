#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
 
const int inf = 1e9 + 7;


struct b {
	int x, y, dir;

	b(int x, int y, int dir) : x(x), y(y), dir(dir) {}

};

inline bool operator<(const b& o1, const b& o2)
{	
	if (o1.x != o2.x) return o1.x < o2.x;
	if (o1.y != o2.y) return o1.y < o2.y;
	return o1.dir < o2.dir;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);

   	int t;
   	cin >> t;
   	while(t--) {
   		set<b> a;
   		int x = 0, y = 0;
   		string s;
   		cin >> s;
   		int res = 0;
   		for(char i : s) {
   			int dir = 0;
   			int p_x = x, p_y = y;

   			if (i == 'S') {
   				dir = 0;
   				x++;
   			}
   			if (i == 'N') {
   				dir = 3;
   				x--;
   			}
   			if (i == 'W') {
   				dir = 1;
   				y++;
   			}
   			if (i == 'E') {
   				dir = 2;
   				y--;
   			}

   			b qqq = b(p_x, p_y, dir);
   			if (a.find(qqq) != a.end()) res++;
   			else res += 5; 
   			a.emplace(p_x, p_y, dir);
   			a.emplace(x, y, 3 - dir);
   		}

   		cout << res << endl;
   	}
}
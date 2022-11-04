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
			
	int n, m;
    cin >> n >> m;

    map<pair<int, int>, char> edge;
    int counter1 = 0;
    int counter2 = 0;

    while (m--) {
    	char type;
    	cin >> type;

    	if (type == '+') {
    		int x, y;
    		char ch;
    		cin >> x >> y >> ch;

    		edge[{x, y}] = ch;

    		if (edge[{y, x}] == ch) {
    			counter1++;
    		} else if (edge[{y, x}] != 0) {
    			counter2++;
    		}

    	} else if (type == '-') {
    		int x, y;
    		cin >> x >> y;

    		if (edge[{y, x}] == edge[{x, y}]) {
    			counter1--;
    		} else if (edge[{y, x}] != 0) {
    			counter2--;
    		}

    		edge[{x, y}] = 0;

    	} else if (type == '?') {
    		int k;
    		cin >> k;

    		if (counter1) {
    			cout << "YES\n";
    		}
    		else if (k % 2 == 1 && counter2) {
    			cout << "YES\n";
    		} else {
    			cout << "NO\n";
    		}
    	}
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ever ;true;
#define Dbug(x) cout << "Debug: " << #x << " = " << x << "\n"
#define _ << ", " << 
#define ll long long
#define int ll
#define all(v) v.begin(), v.end()

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T; cin >> T;
    int a, b, c, d, x, y, x1, x2, y1, y2;
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        int maxdelX = b - a, maxdelY = d - c;
        
        if (x < x1 || x > x2 || y < y1 || y > y2)
            cout << "No\n";

        else if (x1 == x2 && (a > 0 || b > 0))
        {
            cout << "No\n";
            continue;
        }
        else if (y1 == y2 && (c > 0 || d > 0))
        {
            cout << "No\n";
            continue;
        }
        else {
            if (maxdelX + x < x1 || maxdelX + x > x2 || maxdelY + y < y1 || maxdelY + y > y2)
                cout << "No\n";
            else 
                cout << "Yes\n";
        }
    }
    
}
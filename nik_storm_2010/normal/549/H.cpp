#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    
    double l = 0, r = 2e9;
    for (int it = 1; it <= 200; it++) {
        double m = (l + r) / 2;
        
        double al = a - m;
        double ar = a + m;
        
        double bl = b - m;
        double br = b + m;
        
        double cl = c - m;
        double cr = c + m;
        
        double dl = d - m;
        double dr = d + m;
        
        double lim1 = min(min(al * dl, al * dr), min(ar * dl, ar * dr));
        double lim2 = max(max(al * dl, al * dr), max(ar * dl, ar * dr));
        
        double lim3 = min(min(bl * cl, bl * cr), min(br * cl, br * cr));
        double lim4 = max(max(bl * cl, bl * cr), max(br * cl, br * cr));
        
        if ((lim1 <= lim3 && lim3 <= lim2) || (lim1 <= lim4 && lim4 <= lim2) || (lim3 <= lim1 && lim1 <= lim4) || (lim3 <= lim2 && lim2 <= lim4)) {
            r = m;
        } else {
            l = m;
        }
    }
    
    cout << setprecision(9) << fixed;
    cout << l << "\n";
    return 0;
}
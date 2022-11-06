#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int u = max(y2+1,y1);
    int d = min(y2-1,y1);
    int r = max(x2+1,x1);
    int l = min(x2-1,x1);
    cout << 2*(u-d+r-l);
}
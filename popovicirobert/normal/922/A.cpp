#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 175
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int x, y;
    ios::sync_with_stdio(false);
    cin >> x >> y;
    ll o = 1, c = 0;
    if(y == 0) {
        cout << "No";
        return 0;
    }
    o += (y -  1);
    c += (y - 1);
    if((c <= x && (x - c) % 2 == 0 && c > 0) || (c == 0 && x == 0))
        cout << "Yes";
    else
        cout << "No";
    //cin.close();
    //cout.close();
    return 0;
}
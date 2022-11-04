#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int q, x;
    ios::sync_with_stdio(false);
    cin >> q;
    while(q > 0) {
        q--;
        cin >> x;
        if(x <= 3 || x == 5 || x == 7 || x == 11) {
            cout << -1;
        }
        else if(x % 4 == 0 || x % 4 == 2) {
            cout << x / 4;
        }
        else {
            cout << x / 4 - 1;
        }
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}
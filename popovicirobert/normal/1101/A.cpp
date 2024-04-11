#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> q;
    while(q > 0) {
        q--;
        int l, r, d;
        cin >> l >> r >> d;
        if(l > d) {
            cout << d << "\n";
        }
        else if(r < d) {
            cout << d << "\n";
        }
        else {
            cout << (r / d + 1) * d << "\n";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}
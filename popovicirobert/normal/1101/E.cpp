#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 5e5;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int a = 0, b = 0;
    for(i = 1; i <= n; i++) {
        int x, y;
        char ch;
        cin >> ch >> x >> y;
        if(x > y) {
            swap(x, y);
        }
        if(ch == '+') {
            a = max(a, x);
            b = max(b, y);
        }
        else {
            if(a <= x && b <= y) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}
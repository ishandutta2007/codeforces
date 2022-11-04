#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

int x[2 * MAXN + 1];
int sol[2 * MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    n /= 2;
    for(i = 2; i <= 2 * n; i += 2) {
        cin >> x[i];
    }
    ll last = 0;
    for(i = 2; i <= 2 * n; i += 2) {
        int d = 1;
        bool flag = 0;
        while(d * d <= x[i]) {
            if(x[i] % d == 0) {
                int cur = x[i] / d;
                if(cur % 2 == d % 2) {
                    int a = (cur - d) / 2, b = (cur + d) / 2;
                    if(a > last) {
                        flag = 1;
                        sol[i] = b;
                        sol[i - 1] = a;
                    }
                }
            }
            d++;
        }
        last = sol[i];
        if(flag == 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    for(i = 1; i <= 2 * n; i++) {
        cout << 1LL * sol[i] * sol[i] - 1LL * sol[i - 1] * sol[i - 1] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}
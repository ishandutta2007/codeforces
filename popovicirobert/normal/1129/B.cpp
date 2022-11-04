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
    int k, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> k;
    int aux = k;
    for(int n = 3; n <= 2000; n++) {
        static vector <int> sol(n + 1);
        k = aux + n;
        if(k % 2 == 0) {
            for(int l = 1; 2 * l < n; l++) {
                if(k % (2 * l) == 0) {
                    int s = k / (2 * l);
                    if(1LL * s * (n - 2 * l) >= l * l) {
                        for(i = 1; i <= l; i++) {
                            sol[i] = 1;
                            sol[i + l] = -1;
                        }
                        sol[2 * l] = -2;
                        for(i = n; i > 2 * l; i--) {
                            sol[i] = min(s, (int) 1e6);
                            s -= sol[i];
                        }
                        if(s == 0) {
                            cout << n << "\n";
                            for(i = 1; i <= n; i++) {
                                cout << sol[i] << " ";
                            }
                            return 0;
                        }
                    }
                }
            }
        }
        else {
            for(int l = 2; 2 * l - 1 < n; l++) {
                if(k % (2 * l - 1) == 0) {
                    int s = k / (2 * l - 1);
                    if(1LL * s * (n - 2 * l + 1) >= l * l) {
                        for(i = 1; i <= l; i++) {
                            sol[i] = 1;
                        }
                        for(i = l + 1; i < 2 * l - 1; i++) {
                            sol[i] = -1;
                        }
                        sol[2 * l - 1] = -3;
                        for(i = n; i >= 2 * l; i--) {
                            sol[i] = min(s, (int) 1e6);
                            s -= sol[i];
                        }
                        if(s == 0) {
                            cout << n << "\n";
                            for(i = 1; i <= n; i++) {
                                cout << sol[i] << " ";
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << -1;
    //cin.close();
    //cout.close();
    return 0;
}
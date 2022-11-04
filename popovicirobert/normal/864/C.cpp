#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline void impossible() {
    cout << -1;
    exit(0);
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, k, a, b, f;
    ios::sync_with_stdio(false);
    cin >> a >> b >> f >> k;
    int ans = 0;
    int tot = b;
    if(tot < f || tot < a - f)
        impossible();
    for(i = 1; i <= k; i++) {
        if(i == k) {
            if(i % 2 == 1) {
                if(tot < f)
                    impossible();
                else if(tot < a)
                    ans++;
            }
            else {
                if(tot < a - f)
                    impossible();
                else if(tot < a)
                    ans++;
            }
        }
        else {
            if(i % 2 == 1) {
                if(tot < f)
                    impossible();
                else if(tot < a + a - f) {
                    ans++;
                    tot = b - (a - f);
                }
                else
                    tot -= a;
            }
            else {
                if(tot < a - f)
                    impossible();
                else if(tot < a + f) {
                    ans++;
                    tot = b - f;
                }
                else
                    tot -= a;
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
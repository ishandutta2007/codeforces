#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

int fr[MAXN + 1], a[MAXN + 1];
int sol[MAXN + 1], aux[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        fr[n - a[i]]++;
    }
    bool ans = 1;
    for(i = 1; i <= n; i++) {
        if(fr[i] > 0 && fr[i] % i) {
            ans = 0;
        }
        aux[i] = fr[i];
    }
    if(ans) {
        cout << "Possible" << "\n";
        int cur = 0;
        for(i = 1; i <= n; i++) {
            if((fr[n - a[i]] - aux[n - a[i]]) % (n - a[i]) == 0) {
                sol[n - a[i]] = ++cur;
            }
            aux[n - a[i]]--;
            cout << sol[n - a[i]] << " ";
        }
    }
    else {
        cout << "Impossible";
    }
    //cin.close();
    //cout.close();
    return 0;
}
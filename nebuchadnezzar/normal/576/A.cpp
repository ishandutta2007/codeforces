#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n;
vector <int> ans;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 2; i <= n; ++i) {
        bool flag = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int now = i;
            while (now <= n) {
                ans.puba(now);
                now *= i;
            }
        }
    }

    

    cout << szof(ans) << endl;

    for (int i = 0; i < szof(ans); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
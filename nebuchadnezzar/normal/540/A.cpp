#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;

int n;
string s1, s2;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> s1 >> s2;

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += min(abs((int) s1[i] - s2[i]), 10 - abs((int) s1[i] - s2[i]));
    }

    cout << ans << endl;

    return 0;
}
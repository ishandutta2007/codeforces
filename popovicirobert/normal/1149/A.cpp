#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

/*
const int MOD = ;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}
*/

using namespace std;



int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> fr(3);
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        fr[x]++;
    }

    if(fr[2]) {
        cout << 2 << " ";
        fr[2]--;
    }
    if(fr[1]) {
        cout << 1 << " ";
        fr[1]--;
    }
    while(fr[2] > 0) {
        fr[2]--;
        cout << 2 << " ";
    }
    while(fr[1] > 0) {
        fr[1]--;
        cout << 1 << " ";
    }

    //cin.close();
    //cout.close();
    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 175
// 44

using namespace std;

ll n, k;

inline void check(ll x) {
    if(x <= k) {
        cout << "No";
        exit(0);
    }
    cout << "Yes";
    exit(0);
}

const int MAXN = (int) 5e5;

int fr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if(n % 2 == 0) {
        check(2);
    }
    if(n % 6 == 1 || n % 6 == 3) {
        check(3);
    }
    int x = 1;
    int lim = min((ll) MAXN, k);
    while(x <= lim && fr[n % x] == 0) {
        fr[n % x]++;
        x++;
    }
    if(x == lim + 1) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    //cin.close();
    //cout.close();
    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 92

using namespace std;

const int MAXN = (int) 1e5;

int bit[3 * MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int k, i;
    ll n;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 0; i < 60; i++) {
        if(n & (1LL << i)) {
            bit[i + 2 * MAXN]++;
            k--;
        }
    }
    if(k < 0) {
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    for(i = 59 + 2 * MAXN; i > 0; i--) {
        while(k > 0 && bit[i] > 0) {
            bit[i]--;
            bit[i - 1] += 2;
            k--;
        }
    }
    int mx = 0;
    for(i = 59 + 2 * MAXN; i >= 0; i--) {
        if(bit[i]) {
            mx = i;
            break;
        }
    }
    i = 0;
    while(bit[i] == 0) {
        i++;
    }
    int mn = i;
    for(i = mn; i < mx; i++) {
        int x = 0;
        if(i == mn && bit[i] == 2)
            continue;
        if(i == mn) {
            bit[i + 1] += (bit[i] - 1) / 2;
            x = (bit[i] - 1) / 2;
        }
        else {
            bit[i + 1] += bit[i] / 2;
            x = bit[i] / 2;
        }
        while(x > 0) {
            x--;
            bit[mn]--;
            bit[mn - 1] += 2;
            mn--;
        }
        bit[i] %= 2;
    }
    for(i = mx; i >= 0; i--) {
        while(bit[i] > 0) {
            bit[i]--;
            cout << i - 2 * MAXN << " ";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}
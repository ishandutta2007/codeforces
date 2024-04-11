#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 206
// 44

using namespace std;

bool f[1000];
string str;

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> str;
    char mn = 'z', mx = 'a';
    for(auto it : str) {
        mn = min(mn, it);
        mx = max(mx, it);
        f[it] = 1;
    }
    if(k > n) {
        cout << str;
        k -= n;
        while(k > 0) {
            cout << mn;
            k--;
        }
    }
    else {
        i = k - 1;
        while(i >= 0 && str[i] == mx) {
            i--;
        }
        for(int j = 0; j < i; j++) {
            cout << str[j];
        }
        for(char j = str[i] + 1; j <= 'z'; j++) {
            if(f[j]) {
                cout << j;
                break;
            }
        }
        for(int j = i + 1; j < k; j++) {
            cout << mn;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}
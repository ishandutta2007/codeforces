#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 1000;

bool sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i;
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    n = str.size();
    char mn = str[0];
    for(i = 1; i < n; i++) {
        if(mn >= str[i]) {
            sol[i - 1] ^= 1;
            sol[i] ^= 1;
        }
        mn = min(mn, str[i]);
    }
    for(i = 0; i < n; i++) {
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

string str1, str2;
int fr[4];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> str1 >> str2;
    for(i = 0; i < n; i++) {
        int x = (str1[i] - '0') * 2 + str2[i] - '0';
        fr[x]++;
    }
    ll ans = 1LL * fr[0] * (fr[2] + fr[3]) + 1LL * fr[1] * fr[2];
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
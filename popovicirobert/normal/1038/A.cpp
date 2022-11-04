#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

string str;
int fr[26];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> str;
    for(auto it : str) {
        fr[it - 'A']++;
    }
    int cnt = 0;
    int mn = 1e9;
    for(i = 0; i < k; i++) {
        cnt += (fr[i] > 0);
        mn = min(mn, fr[i]);
    }
    if(cnt < k) {
        cout << 0;
        return 0;
    }
    cout << mn * k;
    //cin.close();
    //cout.close();
    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

string str;
map <string, int> mp;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> str;
        cout << (mp[str] ? "YES" : "NO") << "\n";
        mp[str]++;
    }
    //cin.close();
    //cout.close();
    return 0;
}
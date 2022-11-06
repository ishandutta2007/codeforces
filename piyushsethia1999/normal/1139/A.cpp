#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    string s; cin >> s;
    int cn = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (!((s[i] - '0') & 1)) {
            cn += (i + 1);
            // print(i);
        } 
    }
    cout << cn << "\n";
}
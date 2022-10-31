#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        for (int i = n - 2; i >= 0; i--) {
            int a = s[i] - '0', b = s[i + 1] - '0';
            if (a + b >= 10 || i == 0) {
                for (int j = 0; j < i; j++) cout << s[j];
                cout << a + b;
                for (int j = i + 2; j < n; j++) cout << s[j];
                break;
            }
        }
        cout << endl;
    }
    return 0;
}
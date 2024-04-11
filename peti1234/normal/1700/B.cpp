#include <bits/stdc++.h>

using namespace std;
void solve() {
    long long f;
    string s;
    cin >> f >> s;
    if (s[0]!='9') {
        for (int i=0; i<f; i++) {
            cout << (char)('0'+'9'-s[i]);
        }
        cout << "\n";
    } else {
        vector<int> ans(f, 0);
        bool spec=0, kov=0;
        for (int i=f-1; i>=0; i--) {
            int g=s[i]-'0';
            if (g+spec>1) {
                kov=1;
                ans[i]=11-g-spec;
            } else {
                ans[i]=1-g-spec;
            }
            spec=kov;
            kov=0;
        }
        for (auto x:ans) {
            cout << x;
        }
        cout << "\n";
    }

}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
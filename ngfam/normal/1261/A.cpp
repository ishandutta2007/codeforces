#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("1.inp" ,"r")) freopen("1.inp", "r", stdin);

    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << n << endl;

        for(int i = 0; i < k - 1; ++i) {
            int p = i + i, q = p + 1;

            for(int j = p; j < n; ++j) {
                if(s[j] == '(') {
                    reverse(s.begin() + p, s.begin() + j + 1);
                    cout << p + 1 << " " << j + 1 << "\n";
                    break;
                }
            }

            for(int j = q; j < n; ++j) {
                if(s[j] == ')') {
                    reverse(s.begin() + q, s.begin() + j + 1);
                    cout << q + 1 << " " << j + 1 << "\n";
                    break;
                }
            }
        }



        for(int i = 2 * (k - 1); i < n; ++i) {
            bool flag = false;
            for(int j = i; j < n; ++j) if(s[j] == '(') {
                reverse(s.begin() + i, s.begin() + j + 1);
                cout << i + 1 << " " << j + 1 << endl;
                flag = true;
                break;
            }
            if(!flag) cout << i + 1 << " " << i + 1 << endl;
        }
    }
    return 0;
}
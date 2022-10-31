#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string a, s, b = "";
        cin >> a >> s;

        int j = (int)(s.size()) - 1;
        for (int i = (int)(a.size()) - 1; i >= 0; i--){
            if (j == -1) {
                j = -2;
                break;
            }
            if (a[i] <= s[j]){
                b += '0' + s[j] - a[i];
                j--;
            }
            else{
                if (j == 0 || s[j - 1] == '0'){
                    j = -2;
                    break;
                }
                int val = a[i] - '0', need = (s[j - 1] - '0') * 10 + s[j] - '0';
                if (need - val >= 10){
                    j = -2;
                    break;
                }
                b += (need - val) + '0';
                j -= 2;
            }
        }
        if (j == -2){
            cout << -1 << endl;
        }
        else{
            for (int k = j; k >= 0; k--){
                b += s[k];
            }
            while(b.back() == '0') b.pop_back();
            reverse(b.begin(), b.end());
            cout << b << endl;
        }
    }
    return 0;
}
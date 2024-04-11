#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int n, q;
map<string, int> msi;
map<string, int> msp;
string s[10005];
int main() {
    cin >> n;
    //string s;
    for (int k = 0; k < n; k++) {
        cin >> s[k];
        map<string, bool> msb;
        for (int i = 0; i < s[k].length(); i++) {
            for (int j = 1; j <= s[k].length() - i; j++) {
                string sub = s[k].substr(i, j);
                //cout << sub << endl;
                if (!msb[sub]) {
                    msi[sub]++;
                    msp[sub] = k;
                    msb[sub] = true;
                }
            }
        }
    }
    cin >> q;
    //char qs[10];
    string qs;
    for (int i = 0; i < q; i++) {
        //scanf("%s", qs);
        cin >> qs;
        int ans = msi[qs];
        printf("%d ", ans);
        if (ans)
        cout << s[msp[qs]];
        else {
            printf("-");
        }
        puts("");
    }
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    string str;
    cin >> n;
    cin >> str;
    int ans = 0, l, r;
    for(i = 0; i < n; i++) {
        vector <int> fr(26);
        int mx = 0;
        for(j = i; j < n; j++) {
            fr[str[j] - 'a']++;
            mx = max(mx, fr[str[j] - 'a']);
            if(mx <= (j - i + 1) / 2) {
                if(ans < j - i + 1) {
                    ans = j - i + 1;
                    l = i, r = j;
                }
            }
        }
    }
    if(ans > 0) {
        cout << "YES\n";
        for(i = l; i <= r; i++) {
            cout << str[i];
        }
    }
    else {
        cout << "NO";
    }
    //cin.close();
    //cout.close();
    return 0;
}
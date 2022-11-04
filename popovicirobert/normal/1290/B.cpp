#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> str;
    n = str.size(), str = " " + str;

    for(auto &it : str) {
        it -= 'a';
    }

    vector < vector <int> > sp(n + 1, vector <int>(26));
    for(i = 1; i <= n; i++) {
        for(int j = 0; j < 26; j++) {
            sp[i][j] = sp[i - 1][j];
        }
        sp[i][str[i]]++;
    }

    vector <int> nxt(n + 1, n);
    for(i = n - 1; i >= 1; i--) {
        nxt[i] = (str[i] == str[i + 1] ? nxt[i + 1] : i);
    }

    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;

        int cnt = 0;
        for(i = 0; i < 26; i++) {
            cnt += ((sp[r][i] - sp[l - 1][i]) > 0);
        }

        if(cnt == 1) {
            cout << (l == r ? "Yes" : "No");
        }
        else {
            if(cnt > 2) {
                cout << "Yes";
            }
            else {
                cout << (str[l] == str[r] ? "No" : "Yes");
            }
        }
        cout << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long

using namespace std;

const int MAXN = 5000;
const int B = 41;

string a[MAXN + 1], b[MAXN + 1];
string sol_a, sol_b;
int l[MAXN + 1], r[MAXN + 1];

ull hsh[MAXN + 1], pw[MAXN + 1];

inline ull get(int l, int r) {
    return hsh[r] - pw[r - l + 1] * hsh[l - 1];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int len = -1;
    for(i = 1; i <= n; i++) {
        l[i] = r[i] = -1;
        for(int j = 0; j < a[i].size(); j++) {
            if(a[i][j] != b[i][j]) {
                if(l[i] == -1) {
                    l[i] = j;
                }
                r[i] = j;
            }
        }
        if(l[i] > -1) {
            if(len == -1) {
                len = r[i] - l[i] + 1;
            }
            else if(len != r[i] - l[i] + 1) {
                cout << "NO";
                return 0;
            }
        }
    }
    bool flag = 1;
    while(flag) {
        char ch1 = '0', ch2 = '0';
        for(i = 1; i <= n && flag; i++) {
            if(l[i] > 0) {
                if(ch1 == '0') {
                    ch1 = a[i][l[i] - 1];
                    ch2 = b[i][l[i] - 1];
                }
                else if(ch1 != a[i][l[i] - 1] || ch2 != b[i][l[i] - 1]) {
                    flag = 0;
                }
            }
            else if(l[i] > -1) {
                flag = 0;
            }
        }
        if(flag == 0) {
            break;
        }
        for(i = 1; i <= n; i++) {
            if(l[i] > -1) {
                l[i]--;
            }
        }
    }
    flag = 1;
    while(flag) {
        char ch1 = '0', ch2 = '0';
        for(i = 1; i <= n && flag; i++) {
            if(r[i] > -1 && r[i] + 1 < a[i].size()) {
                if(ch1 == '0') {
                    ch1 = a[i][r[i] + 1];
                    ch2 = b[i][r[i] + 1];
                }
                else if(ch1 != a[i][r[i] + 1] || ch2 != b[i][r[i] + 1]) {
                    flag = 0;
                }
            }
            else if(r[i] > -1) {
                flag = 0;
            }
        }
        if(flag == 0) {
            break;
        }
        for(i = 1; i <= n; i++) {
            if(r[i] > -1) {
                r[i]++;
            }
        }
    }
    for(i = 1; i <= n; i++) {
        if(l[i] > -1) {
            for(int j = l[i]; j <= r[i]; j++) {
                sol_a.push_back(a[i][j]);
                sol_b.push_back(b[i][j]);
            }
            break;
        }
    }
    for(i = 1; i <= n; i++) {
        //cerr << l[i] << " " << r[i];
        int pos = a[i].find(sol_a);
        bool ok = 1;
        if(pos < a[i].size()) {
            ok = 0;
            for(int j = 0; j < sol_a.size(); j++) {
                if(sol_b[j] != b[i][j + pos]) {
                    cout << "NO";
                    return 0;
                }
            }
        }
        if(ok && a[i] != b[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << "\n";
    cout << sol_a << "\n" << sol_b;
    //cin.close();
    //cout.close();
    return 0;
}
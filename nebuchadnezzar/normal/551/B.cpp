#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;

string a;
string s[2];
int num[3][26];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> a;
    for (int i = 0; i < szof(a); ++i) {
        num[0][a[i] - 'a']++;
    }
    cin >> s[0];
    cin >> s[1];

    if (szof(s[0]) > szof(s[1])) {
        swap(s[0], s[1]);
    }
    
    for (int i = 0; i < szof(s[0]); ++i) {
        num[1][s[0][i] - 'a']++;
    }
    
    for (int i = 0; i < szof(s[1]); ++i) {
        num[2][s[1][i] - 'a']++;
    }

    int num1 = 0, num2 = 0;
    for (int i = 0; ; ++i) {
        //cerr << i << endl;
        int nu = 1e6;
        bool flag = true;
        for (int j = 0; j < 26; ++j) {
            if (num[1][j] * i > num[0][j]) {
                flag = false;
                break;
            }
            if (num[2][j]) {
                nu = min(nu, (num[0][j] - num[1][j] * i) / num[2][j]);
            }
        }
        if (!flag) {
            break;
        }
        if (num1 + num2 < i + nu) {
            num1 = i;
            num2 = nu;
        }
    }
    //cout << "@" << endl;

    for (int i = 0; i < num1; ++i) {
        cout << s[0];
    }
    for (int i = 0; i < num2; ++i) {
        cout << s[1];
    }

    for (int i = 0; i < 26; ++i) {
        num[0][i] -= num[1][i] * num1 + num[2][i] * num2;
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < num[0][i]; ++j) {
            cout << (char) ('a' + i);
        }
    }
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = 5000;

string str;

inline bool check(string cur) {
    int n = cur.size();
    int i = 0;
    while(i < n - i - 1 && cur[i] == cur[n - i - 1]) {
        i++;
    }
    return i >= n - i - 1;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> str;
    n = str.size();
    for(i = 0; i < n; i++) {
        string cur = str.substr(i + 1, n) + str.substr(0, i + 1);
        if(check(cur) && cur != str) {
            cout << 1;
            return 0;
        }
    }
    for(i = 0; i < n / 2; i++) {
        if(!check(str.substr(0, i + 1))) {
            cout << 2;
            return 0;
        }
    }
    cout << "Impossible";
    //cin.close();
    //cout.close();
    return 0;
}
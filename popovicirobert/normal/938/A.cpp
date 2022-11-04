#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

char stk[101];

inline bool ok(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    char ch;
    ios::sync_with_stdio(false);
    cin >> n;
    int sz = 0;
    for(i = 1; i <= n; i++) {
        cin >> ch;
        if(ok(stk[sz]) == 0 || ok(ch) == 0)
            stk[++sz] = ch;
    }
    for(i = 1; i <= sz; i++) {
        cout << stk[i];
    }
    //cin.close();
    //cout.close();
    return 0;
}
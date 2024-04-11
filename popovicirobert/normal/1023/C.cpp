#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

char stk[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, k, i;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int cnt = 0, sz = 0;
    for(i = 1; i <= n; i++) {
        char ch;
        cin >> ch;
        if(ch == '(') {
            stk[++sz] = ch;
        }
        else {
            if(cnt < n - k) {
                cnt += 2;
                sz--;
            }
            else {
                stk[++sz] = ch;
            }
        }
    }
    for(i = 1; i <= sz; i++) {
        cout << stk[i];
    }
    //cin.close();
    //cout.close();
    return 0;
}
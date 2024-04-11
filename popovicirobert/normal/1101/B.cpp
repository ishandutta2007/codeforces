#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 5e5;

char str[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> str;
    n = strlen(str);
    int pos1 = -1, pos2 = -1;
    int cnt = 0;
    for(i = 0; i < n; i++) {
        if(cnt == 0 && str[i] == '[') {
            cnt++;
        }
        if(cnt == 1 && str[i] == ':') {
            cnt++;
            pos1 = i;
        }
    }
    cnt = 0;
    for(i = n - 1; i >= 0; i--) {
        if(cnt == 0 && str[i] == ']') {
            cnt++;
        }
        if(cnt == 1 && str[i] == ':') {
            cnt++;
            pos2 = i;
        }
    }
    if(pos1 == -1 || pos2 == -1 || pos1 >= pos2) {
        cout << -1;
        return 0;
    }
    cnt = 0;
    for(i = pos1; i <= pos2; i++) {
        if(str[i] == '|') {
            cnt++;
        }
    }
    cout << cnt + 4;
    //cin.close();
    //cout.close();
    return 0;
}
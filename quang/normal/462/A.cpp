#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 110

using namespace std;

int n;
string s[N];

bool check() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int cnt = 0;
            if(j > 0) cnt += (s[i][j - 1] == 'o');
            if(j < n - 1) cnt += (s[i][j + 1] == 'o');
            if(i > 0) cnt += (s[i - 1][j] == 'o');
            if(i < n - 1) cnt += (s[i + 1][j] == 'o');
            if(cnt % 2) return 0;
        }
    }
    return 1;
}

int main() {
   // fi, fo;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    if(check()) cout << "YES";
    else cout << "NO";
    return 0;
}
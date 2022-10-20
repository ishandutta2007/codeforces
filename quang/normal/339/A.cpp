#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 110

using namespace std;

string s;
char a[N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> s;
    int d = 0;
    for(int i = 0; i < (int)s.size(); i += 2) a[++d] = s[i];
    sort(a + 1, a + d + 1);
    cout << a[1];
    for(int i = 2; i <= d; i++) cout << "+" << a[i];
    return 0;
}
#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 100010

using namespace std;

int n, sum, ans;
int a[N];
string s;

int main() {
    //fi, fo;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i), sum += a[i];
    cin >> s;
    for(int i = n - 1; i >= 0; i--)
    if(s[i] == '0') sum -= a[i];
    else ans = max(ans, sum - a[i]);
    cout << max(ans, sum);
    return 0;
}
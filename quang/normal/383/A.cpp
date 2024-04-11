#include <bits/stdc++.h>
#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 200010;

int n;
int a[N];
long long res = 0;

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int sl = 0;
    for(int i = 1; i <= n; i++)
        if(a[i]) sl++;
        else res += sl;
    cout << res;
    return 0;
}
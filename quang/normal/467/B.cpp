#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;


int n, m, k, res = 0;
int a[1010];

bool Check(int x){
    int sl = 0;
    for(int i = 0; i < n; i++)
    if((x >> i) & 1) sl++;
    return (sl <= k);
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> m >> k;
    for(int i = 1; i <= m + 1; i++) cin >> a[i];
    for(int i = 1; i <= m; i++)
    if(Check(a[i] ^ a[m + 1])) res++;
    cout << res;
    return 0;
}
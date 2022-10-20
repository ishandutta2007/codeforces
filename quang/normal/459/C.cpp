#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 1010

using namespace std;

int n, k, d, sl = 0;
int a[N][N], b[N];

bool check()
{
    long long gt = 1;
    for(int i = 1; i <= d; i++) {
        gt *= k;
        if(gt >= 1ll * n) return 1;
    }
    return 0;
}

void Try(int u)
{
    if(u > d) {
        sl++;
        for(int i = 1; i <= d; i++) a[sl][i] = b[i];
        return ;
    }
    for(int i = 1; i <= k; i++) {
        b[u] = i;
        Try(u + 1);
        if(sl >= n) return;
    }
}

void xuli()
{
    memset(a, 0, sizeof(a));
    memset(b, 0 ,sizeof(b));
    if(check()){
        Try(1);
        for(int i = 1; i <= d; i++) {
            for(int j = 1; j <= n; j++) cout << a[j][i] << " ";
            cout << endl;
        }
    }
    else{
        cout << -1;
        return;
    }
}

int main()
{
   // fi, fo;
    scanf("%d%d%d", &n, &k, &d);
    if(n == 1) {
        for(int i = 1; i <= d; i++) cout << 1 << endl;
        return 0;
    }
    else {
        if(d == 1) {
            if(k < n) {
                cout << -1;
                return 0;
            }
            else {
                for(int i = 1; i <= n; i++) cout << i << " ";
                return 0;
            }
        }
        else{
            xuli();
            return 0;
        }
    }
    return 0;
}
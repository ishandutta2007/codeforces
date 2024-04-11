#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 100010

using namespace std;

int n, m;
long long kq;
int a[N];
bool b[20][N];

bool BIT(int x, int l) {
    return ((x >> l) & 1);
}

long long Res() {
    long long res = 0;
    for(int i = 0; i < 20; i++) {
        int cuoi = n;
        for(int j = n; j >= 0; j--) {
            if(((a[j] >> i) & 1) == 0) {
                res += (1ll * (cuoi - j) * (cuoi - j + 1) / 2) << i;
                cuoi = j - 1;
            }
        }
    }
    return res;
}

int Timcuoi(int u, int vt) {
    for(int i = vt; i <= n + 1; i++)
    if(b[u][i] == 0) return i;
}

int Timdau(int u, int vt) {
    for(int i = vt; i >= 0; i--)
        if(b[u][i] == 0) return i;
}

void Change(int u, int v, bool gt) {
    int cuoi = Timcuoi(u, v + 1);
    int dau = Timdau(u, v - 1);
    b[u][v] = gt;
    if(gt == 1) {
        kq -= (((1ll * (cuoi - v - 1) * (cuoi - v) + 1ll * (v - dau - 1) * (v - dau)) / 2) << u);
        kq += ((1ll * (cuoi - dau - 1) * (cuoi - dau) / 2) << u);
    }
    else {
        kq += (((1ll * (cuoi - v - 1) * (cuoi - v) + 1ll * (v - dau - 1) * (v - dau)) / 2) << u);
        kq -= ((1ll * (cuoi - dau - 1) * (cuoi - dau) / 2) << u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < 20; i++)
        for(int j = 1; j <= n; j++) b[i][j] = ((a[j] >> i) & 1);
    kq = Res();
    while(m--) {
        int p, v;
        cin >> p >> v;
        for(int i = 0; i < 20; i++)
        if(BIT(a[p], i) ^ BIT(v, i))
        {
            Change(i, p, BIT(v, i));
        }
        cout << kq << endl;
        a[p] = v;
    }
    return 0;
}
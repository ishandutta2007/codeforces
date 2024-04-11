#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY 100000010
#define LIMIT 150

using namespace std;

int n, d, kq;
int a[LIMIT], c[LIMIT][LIMIT], du[LIMIT];
typedef pair<int, int> pi;
pi b[LIMIT];
bool used[LIMIT];

bool Check(int m)
{
    memset(du, -1, sizeof(du));
    memset(used, 0, sizeof(used));
    du[1] = m;
    while(1)
    {
        int res = 0;
        for(int i = 1; i <= n; i++)
        if(!used[i] && du[i] > du[res]) res = i;
        if(!res || res == n) break;
        used[res] = 1;
        for(int i = 1; i <= n; i++)
        if(!used[i])
        if(du[res] >= d * c[res][i]) du[i] = max(du[i], du[res] - d * c[res][i] + a[i]);
    }
    return(du[n] >= 0);
}

int BS()
{
    int l = 0, r = EXTREMELY, m;
    while(r - l > 1)
    {
        m = l + r >> 1;
        if(Check(m)) r = m;
        else l = m;
    }
    return r;
}

int main()
{
    //filein, fileout;
    scanf("%d%d", &n, &d);
    for(int i = 2; i < n; i++) scanf("%d", a + i);
    for(int i = 1; i <= n; i++) scanf("%d%d", &b[i].first, &b[i].second);
    for(int i = 1; i < n; i++)
        for(int j = i; j <= n; j++)
            c[i][j] = c[j][i] = abs(b[i].first - b[j].first) + abs(b[i].second - b[j].second);
    kq = BS();
    cout << kq;
    return 0;
}
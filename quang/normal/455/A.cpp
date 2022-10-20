#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY 100010
#define LIMIT 100010

using namespace std;

int n, d = 0;
int a[LIMIT];
typedef pair <int, int> pi;
pi b[LIMIT];
long long gt[LIMIT][2];

int main()
{
   // filein, fileout;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    a[n + 1] = EXTREMELY;
    sort(a + 1, a + n + 1);
    int tr = 1;
    for(int i = 2; i <= n + 1; i++)
    {
        if(a[i] != a[i - 1])
        {
            b[++d] = make_pair(a[i - 1], i - tr);
            tr = i;
        }
    }
    for(int i = 1; i <= d; i++)
    {
        if(i == 1)
        {
            gt[i][0] = -1ll * EXTREMELY * EXTREMELY;
            gt[i][1] = 1ll * b[i].first * b[i].second;
        }
        else
        {
            if(b[i].first - 1 == b[i - 1].first)
            {
                gt[i][0] = gt[i - 1][1];
                gt[i][1] = 1ll * b[i].first * b[i].second + max(gt[i - 2][0], gt[i - 2][1]);
            }
            else
            {
                gt[i][0] = -1ll * EXTREMELY * EXTREMELY;
                gt[i][1] = 1ll * b[i].first * b[i].second + max(gt[i - 1][0], gt[i - 1][1]);
            }
        }
    }
    cout << max(gt[d][0], gt[d][1]);
    return 0;
}
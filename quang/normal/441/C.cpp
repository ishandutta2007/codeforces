#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 1010

using namespace std;

int n, m, k;
vector < pair<int, int> > a;

int main()
{
    //fi, fo;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
    {
        if(i % 2) for(int j = 1; j <= m; j++) a.push_back( make_pair(i, j));
        else for(int j = m; j >= 1; j--) a.push_back( make_pair(i, j));
    }
    if(k == 1)
    {
        printf("%d ", a.size());
        for(int i = 0; i < (int)a.size(); i++) printf("%d %d ", a[i].first, a[i].second);
    }
    else
    {
        int sl = 0;
        for(int i = 1; i < k; i++)
        {
            printf("2 %d %d %d %d\n", a[sl].first, a[sl].second, a[sl + 1].first, a[sl + 1].second);
            sl += 2;
        }
        cout << (int)a.size() - sl << " " ;
        for(int i = sl; i < (int)a.size(); i++) printf("%d %d ", a[i].first, a[i].second);
    }
    return 0;
}
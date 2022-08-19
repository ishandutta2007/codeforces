#include <bits/stdc++.h>
using namespace std;

int n, m;

char wcz[1000007];

char wpom[1000007];

vector <char> slo[1000007];

int l;
int syn[1000007][27];

int cotu[1000007];

int dp[1000007];

char p;

int u;

int v;

vector <int> wyn;

inline char f(char vv)
{
    if (vv>='a' && vv<='z')
    return vv-'a';
    return vv-'A';
}

int main()
{
    scanf("%d", &n);
    scanf("%s", wcz+1);
    scanf("%d", &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%s", wpom);
        v=0;
        for (int j=0; 1; j++)
        {
            if (!wpom[j])
            break;
            slo[i].push_back(wpom[j]);
            p=f(slo[i].back());
            if (!syn[v][p])
            {
                l++;
                syn[v][p]=l;
            }
            v=syn[v][p];
        }
        cotu[v]=i;
    }
    dp[0]=-1;
    for (int i=1; i<=n; i++)
    {
        v=0;
        for (int j=i; j; j--)
        {
            p=f(wcz[j]);
            if (!syn[v][p])
            break;
            v=syn[v][p];
            if (cotu[v] && dp[j-1])
            {
                dp[i]=cotu[v];
            }
        }
    }
    v=n;
    while(v)
    {
        wyn.push_back(dp[v]);
        v-=slo[dp[v]].size();
    }
    while(!wyn.empty())
    {
        u=wyn.back();
        wyn.pop_back();
        for (int i=0; i<slo[u].size(); i++)
        printf("%c", slo[u][i]);
        printf(" ");
    }
    printf("\n");
    return 0;
}
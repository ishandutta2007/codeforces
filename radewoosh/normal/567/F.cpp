#include <bits/stdc++.h>
using namespace std;

int n, k;

string co[107];
pair <int,int> tab[107];

vector <int> lew[107];
vector <int> pra[107];

long long dp[107][107];

int czy;

int u;

int main()
{
    cin >> n >> k;
    for (int i=1; i<=k; i++)
    {
        cin >> tab[i].first >> co[i] >> tab[i].second;
        if (tab[i].first>tab[i].second)
        {
            swap(tab[i].first, tab[i].second);
            if (co[i][0]=='>')
            {
                co[i][0]='<';
            }
            else
            {
                if (co[i][0]=='<')
                {
                    co[i][0]='>';
                }
            }
        }
        if (tab[i].first==tab[i].second && co[i]!="=" && co[i]!=">=" && co[i]!="<=")
        {
            printf("0");
            return 0;
        }
        lew[tab[i].first].push_back(i);
        pra[tab[i].second].push_back(i);
    }
    for (int i=1; i<2*n; i++)
    {
        czy=1;
        for (int j=0; j<lew[i].size(); j++)
        {
            u=lew[i][j];
            if (tab[u].second==(i+1) && (co[u]==">" || co[u]=="<"))
            {
                czy=0;
                break;
            }
        }
        if (czy)
        {
            dp[i][i+1]=1;
        }
    }
    for (int kon=1; kon<=2*n; kon++)
    {
        for (int pocz=kon; pocz; pocz--)
        {
            if ((kon-pocz+1)&1)
            continue;
            if (pocz>2)
            {
                czy=1;
                for (int j=0; j<lew[pocz-2].size(); j++)
                {
                    u=lew[pocz-2][j];
                    if (tab[u].second==(pocz-1) && (co[u]==">" || co[u]=="<"))
                    {
                        czy=0;
                        break;
                    }
                    if (tab[u].second>=pocz && tab[u].second<=kon && (co[u]=="=" || co[u]==">" || co[u]==">="))
                    {
                        czy=0;
                        break;
                    }
                }
                for (int j=0; j<lew[pocz-1].size(); j++)
                {
                    u=lew[pocz-1][j];
                    if (tab[u].second>=pocz && tab[u].second<=kon && (co[u]=="=" || co[u]==">" || co[u]==">="))
                    {
                        czy=0;
                        break;
                    }
                }
                if (czy)
                {
                    dp[pocz-2][kon]+=dp[pocz][kon];
                    //printf("z %d %d do %d %d\n", pocz, kon, pocz-2, kon);
                }
            }
            if (pocz>1 && kon<2*n)
            {
                czy=1;
                for (int j=0; j<lew[pocz-1].size(); j++)
                {
                    u=lew[pocz-1][j];
                    if (tab[u].second==(kon+1) && (co[u]==">" || co[u]=="<"))
                    {
                        czy=0;
                        break;
                    }
                    if (tab[u].second>=pocz && tab[u].second<=kon && (co[u]=="=" || co[u]==">" || co[u]==">="))
                    {
                        czy=0;
                        break;
                    }
                }
                for (int j=0; j<pra[kon+1].size(); j++)
                {
                    u=pra[kon+1][j];
                    if (tab[u].first>=pocz && tab[u].first<=kon && (co[u]=="=" || co[u]=="<" || co[u]=="<="))
                    {
                        czy=0;
                        break;
                    }
                }
                if (czy)
                {
                    dp[pocz-1][kon+1]+=dp[pocz][kon];
                    //printf("z %d %d do %d %d\n", pocz, kon, pocz-1, kon+1);
                }
            }
            if (kon<2*n-1)
            {
                czy=1;
                for (int j=0; j<pra[kon+2].size(); j++)
                {
                    u=pra[kon+2][j];
                    if (tab[u].first==(kon+1) && (co[u]==">" || co[u]=="<"))
                    {
                        czy=0;
                        break;
                    }
                    if (tab[u].first>=pocz && tab[u].first<=kon && (co[u]=="=" || co[u]=="<" || co[u]=="<="))
                    {
                        czy=0;
                        break;
                    }
                }
                for (int j=0; j<pra[kon+1].size(); j++)
                {
                    u=pra[kon+1][j];
                    if (tab[u].first>=pocz && tab[u].first<=kon && (co[u]=="=" || co[u]=="<" || co[u]=="<="))
                    {
                        czy=0;
                        break;
                    }
                }
                if (czy)
                {
                    dp[pocz][kon+2]+=dp[pocz][kon];
                    //printf("z %d %d do %d %d\n", pocz, kon, pocz, kon+2);
                }
            }
        }
    }
    printf("%lld", dp[1][2*n]);
    return 0;
}
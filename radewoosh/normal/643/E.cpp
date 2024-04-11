#include <bits/stdc++.h>
using namespace std;

int q;

int n=1;

int par[500007];

int d=60;

double dp[500007][63];

int p1, p2;

vector <int> sta;

void ans(int v)
{
    double res=0.0;
    for (int i=1; i<=d; i++)
    {
        res+=1.0-dp[v][i];
    }
    printf("%.10lf\n", res);
}

void add(int v)
{
    n++;
    par[n]=v;
    sta.clear();
    v=n;
    for (int i=1; i<=d; i++)
    {
        dp[n][i]=1.0;
    }
    for (int i=1; i<=d+1 && v; i++)
    {
        sta.push_back(v);
        v=par[v];
    }
    for (int i=(int)sta.size()-2; i>0; i--)
    {
        dp[sta[i+1]][i+1]/=(dp[sta[i]][i]+1.0)/2.0;
    }
    for (int i=0; i+1<(int)sta.size(); i++)
    {
        dp[sta[i+1]][i+1]*=(dp[sta[i]][i]+1.0)/2.0;
    }
}

int main()
{
    scanf("%d", &q);
    for (int i=1; i<=d; i++)
    {
        dp[1][i]=1.0;
    }
    while(q--)
    {
        scanf("%d%d", &p1, &p2);
        if (p1==1)
        add(p2);
        else
        ans(p2);
    }
    return 0;
}
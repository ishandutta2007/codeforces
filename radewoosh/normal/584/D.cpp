#include <bits/stdc++.h>
using namespace std;

int n;

vector <int> pie;

vector <int> roz[1000007];

vector <int> wyn;

int test(int v)
{
    for (int i=2; i*i<=v; i++)
    {
        if (!(v%i))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    scanf("%d", &n);
    for (int i=2; i<=3000; i++)
    {
        if (test(i))
        {
            pie.push_back(i);
        }
    }
    for (int i=0; i<pie.size(); i++)
    {
        roz[pie[i]].clear();
        roz[pie[i]].push_back(pie[i]);
        for (int j=i; j<pie.size(); j++)
        {
            roz[pie[i]+pie[j]].clear();
            roz[pie[i]+pie[j]].push_back(pie[i]);
            roz[pie[i]+pie[j]].push_back(pie[j]);
        }
    }
    if (n<=3000 && !roz[n].empty())
    {
        wyn=roz[n];
        printf("%d\n", wyn.size());
        for (int i=0; i<wyn.size(); i++)
        printf("%d ", wyn[i]);
        return 0;
    }
    for (int j=n; j; j--)
    {
        if (test(j))
        {
            if (j==n)
            {
                printf("1\n%d", n);
                return 0;
            }
            if (j==n-1)
            {
                continue;
            }
            if (!roz[n-j].empty())
            {
                wyn=roz[n-j];
                wyn.push_back(j);
                printf("%d\n", wyn.size());
                for (int i=0; i<wyn.size(); i++)
                printf("%d ", wyn[i]);
                return 0;
            }
        }
    }
    return 0;
}
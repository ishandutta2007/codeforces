#include <bits/stdc++.h>

using namespace std;

int v[20],ncif,sol = -1;

void proba(int a)
{
    long long nr = 0,putere = 1;
    int np = 0;
    int last = -1;
    for(int i = 1;i <= ncif;i ++)
    {
        if(a % 2 == 1)
        {
            last = v[i];
            nr += (v[i]*putere);
            putere *= 10;
            np ++;
        }
        a /= 2;
    }
    if(last == 0)
        return;
    int p = sqrt(nr);
    if(p * p == nr)
        sol = max(np,sol);
}

int main()
{
    int n;
    cin >> n;
    int cn = n;
    while(cn != 0)
    {
        ncif ++;
        v[ncif] = cn % 10;
        cn /= 10;
    }
    int putmax = 1 << ncif;
    for(int i = putmax-1;i >= 1;i --)
        proba(i);
    if(sol == -1)
        cout << sol;
    else
        cout << ncif - sol;
    return 0;
}
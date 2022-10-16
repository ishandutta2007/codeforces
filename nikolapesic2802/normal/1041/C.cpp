#include <bits/stdc++.h>

using namespace std;
set<int> vremena;
int g()
{
    set<int>::iterator it=vremena.end();
    it--;
    return *it;
}
int main()
{
    int n,m,d;
    scanf("%i %i %i",&n,&m,&d);
    map<int,int> mapa;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        mapa[a]=i;
        vremena.insert(a);
    }
    int resenje[n];
    int dani=1;
    int tr=1;
    while(!vremena.empty())
    {
        if(g()>=tr)
        {
            int sl=*vremena.lower_bound(tr);
            resenje[mapa[sl]]=dani;
            vremena.erase(vremena.lower_bound(tr));
            tr=sl+d+1;
        }
        else
        {
            dani++;
            tr=1;
        }
    }
    printf("%i\n",dani);
    for(int i=0;i<n;i++)
    {
        printf("%i ",resenje[i]);
    }
    printf("\n");
    return 0;
}
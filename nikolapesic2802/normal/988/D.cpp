#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    const int maxx=1000000001;
    scanf("%i",&n);
    vector<int> kraj;
    set<int> mapa;
    int niz[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
        mapa.insert(niz[i]);
    }
    int m=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<maxx;j*=2)
        {
            int s=1;
            vector<int> c;
            int d=niz[i];
            c.push_back(niz[i]);
            if(mapa.count(d+j))
            {
                c.push_back(d+j);
                s++;
            }
            if(mapa.count(d+2*j))
            {
                c.push_back(d+2*j);
                s++;
            }
            if(s>m)
            {
                kraj.swap(c);
                m=s;
            }
        }
        if(m==3)
        {
            break;
        }
    }
    printf("%i\n",m);
    for(int i=0;i<m;i++)
    {
        printf("%i ",kraj[i]);
    }
    return 0;
}
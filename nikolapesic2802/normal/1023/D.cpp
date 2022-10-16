#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q;
    cin >> n >> q;
    vector<int> p[q+1];
    int niz[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
        p[niz[i]].push_back(i);
    }
    if(p[q].size()==0&&p[0].size()==0)
    {
        printf("NO\n");
        return 0;
    }
    set<int> tester;
    tester.insert(n+1);
    for(int i=1;i<=q;i++)
    {
        //printf("Usao za %i\n",i);
        if(p[i].size()>1)
        {
            int prvi=p[i][0];
            int zadnji=p[i][p[i].size()-1];
            int sledeci=*tester.lower_bound(prvi);
            //printf("Prvi: %i, Zadnji:%i, Sledeci:%i\n",prvi,zadnji,sledeci);
            if(sledeci<zadnji)
            {
                printf("NO\n");
                return 0;
            }
        }
        for(unsigned int j=0;j<p[i].size();j++)
        {
            tester.insert(p[i][j]);
            //printf("Ubacujem %i\n",p[i][j]);
        }
    }
    int rep=0;
    if(p[q].size()==0)
    {
        rep=1;
    }
    printf("YES\n");
    int prosli=1;
    for(int i=0;i<n;i++)
    {
        if(niz[i]==0)
        {
            if(rep==1)
            {
                printf("%i ",q);
                prosli=q;
                rep=0;
            }
            else
            {
                printf("%i ",prosli);
            }
        }
        else
        {
            printf("%i ",niz[i]);
            prosli=niz[i];
        }
    }
    printf("\n");
    return 0;
}
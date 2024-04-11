#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    vector<int> niz;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        niz.push_back(a);
    }
    sort(niz.begin(),niz.end());
    /*for(int i=0;i<n;i++)
    {
        printf("%i ",niz[i]);
    }
    printf("\n");*/
    if(k==0)
    {
        if(niz[0]==1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%i\n",niz[0]-1);
        }
        return 0;
    }
    if(niz[k-1]==niz[k])
    {
        printf("-1\n");
    }
    else
    {
        printf("%i\n",niz[k-1]);
    }
    return 0;
}
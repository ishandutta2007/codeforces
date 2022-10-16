#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
int main()
{
    int n,m,k;
    scanf("%i %i %i",&n,&m,&k);
    vector<int> niz(n);
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
    }
    reverse(niz.begin(),niz.end());
    int tr=0;
    for(int i=0;i<n;i++)
    {
        //printf("Gledam %i\n",niz[i]);
        if(tr+niz[i]<=k)
        {
            //printf("Staje\")
            tr+=niz[i];
        }
        else
        {
            if(m==1)
            {
                printf("%i\n",i);
                return 0;
            }
            m--;
            tr=niz[i];
        }
    }
    printf("%i\n",n);
    return 0;
}
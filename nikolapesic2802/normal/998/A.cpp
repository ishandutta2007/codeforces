#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    pair<int,int> niz[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&(niz[i].first));
        niz[i].second=i;
        //printf("%i\n",niz[i]);
    }
    sort(niz,niz+n);
    if(n==1)
    {
        printf("-1\n");
        return 0;
    }
    if(n==2)
    {
        if(niz[0].first==niz[1].first)
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("1\n%i\n",niz[0].second+1);
    return 0;
}
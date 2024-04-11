#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,b;
    scanf("%i %i",&n,&b);
    int niz[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
    }
    int even=0,odd=0;
    vector<int> cuts;
    for(int i=0;i<n-1;i++)
    {
        if(niz[i]%2==0)
        {
            even++;
        }
        else
        {
            odd++;
        }
        if(even==odd)
        {
            cuts.push_back(abs(niz[i+1]-niz[i]));
        }
    }
    if(niz[n-1]%2==0)
    {
        even++;
    }
    else
    {
        odd++;
    }
    sort(cuts.begin(),cuts.end());
    int res=0;
    if(odd==even)
    {
    int tr=0;
    for(int i=0;i<cuts.size();i++)
    {
        //printf("%i\n",cuts[i]);
        if(tr+cuts[i]<=b)
        {
            res++;
            tr+=cuts[i];
        }
        else
        {
            break;
        }
    }
    }
    printf("%i",res);
    return 0;
}
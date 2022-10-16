#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    vector<int> niz;
    int sizes[1000001]={};
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        sizes[a]++;
    }
    for(int i=1;i<1000001;i++)
    {
        if(sizes[i]>0)
        {
            niz.push_back(i);
        }
    }
    int broj=n;
    for(int i=0;i<niz.size()-1;i++)
    {
        if((niz[i+1]-niz[i])<=k)
        {
            broj-=sizes[niz[i]];
        }
    }
    printf("%i\n",broj);
    return 0;
}
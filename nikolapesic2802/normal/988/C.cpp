#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    scanf("%i",&k);
    long long sum[k]={};
    set<pair<long long,pair<int,int> > > sve_sume;
    for(int l=0;l<k;l++)
    {
        int n;
        scanf("%i",&n);
        int ele[n];
        for(int i=0;i<n;i++)
        {
            scanf("%i",&ele[i]);
            sum[l]+=ele[i];
        }
        for(int i=0;i<n;i++)
        {
            sve_sume.insert(make_pair(sum[l]-ele[i],make_pair(l+1,i+1)));
        }
    }
    set<pair<long long,pair<int,int> > >::iterator it,it2;
    it=sve_sume.begin();
    it2=sve_sume.end();
    it2--;
    while(it!=it2)
    {
        pair<long long,pair<int,int> > pr=*it;
        it++;
        pair<long long,pair<int,int> > sl=*it;
        if(pr.first==sl.first&&pr.second.first!=sl.second.first)
        {
            printf("YES\n%i %i\n%i %i\n",pr.second.first,pr.second.second,sl.second.first,sl.second.second);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
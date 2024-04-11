#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long mod=1000000007;
    long long res=1;
    int n;
    scanf("%i",&n);
    set<long long> buy,sell,un;
    long long max_buy,min_sell;
    set<long long>::iterator it;
    for(int i=0;i<n;i++)
    {
        if(buy.size())
        {
            it=buy.end();
            //printf("%i\n",*it);
            it--;
            //printf("%i\n",*it);
            max_buy=*it;
        }
        else
        {
            max_buy=-1;
        }
        if(sell.size())
        {
            min_sell=*(sell.begin());
        }
        else
        {
            min_sell=308983080;
        }
        if(max_buy>min_sell)
        {
            printf("0\n");
            return 0;
        }
        char niz[7];
        scanf("%s",niz);
        long long b;
        scanf("%I64d",&b);
        if(niz[1]=='D')
        {
            if(max_buy>b)
            {
                buy.insert(b);
            }
            else
            {
                if(min_sell<b)
                {
                    sell.insert(b);
                }
                else
                {
                    un.insert(b);
                }
            }
        }
        else
        {
            if(buy.count(b))
            {
                buy.erase(b);
                if(max_buy!=b)
                {
                    printf("0\n");
                    return 0;
                }
            }
            if(sell.count(b))
            {
                sell.erase(b);
                if(min_sell!=b)
                {
                    printf("0\n");
                    return 0;
                }
            }
            if(un.count(b))
            {
                un.erase(b);
                res=(res*2)%mod;
            }
            for(it=un.begin();it!=un.end();it++)
            {
                if(*it<b) buy.insert(*it);
                else sell.insert(*it);
            }
            un.clear();
        }
    }
    //for(int i=0;i<un.size();i++)
    //{
        res=(res*(un.size()+1))%mod;
    //}
    printf("%I64d\n",res);
    return 0;
}
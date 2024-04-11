#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int tn=n;
        vector<pair<int,int> > fac;
        for(int i=2;i*i<=n;i++)if(n%i==0)
        {
            fac.push_back({i,0});
            while(n%i==0)n/=i,fac.back().second++;
        }
        if(n>1)fac.push_back({n,1});
        int a=0,b=0,c=0;
        for(size_t i=0;i<fac.size();i++)
        {
            if(fac[i].second<3)continue;
            int ta=fac[i].first,tb=ta*ta,tc=tn/ta/tb;
            if(tc>1 && tc!=ta && tc!=tb)a=ta,b=tb,c=tc;
        }
        for(size_t i=0;i<fac.size();i++)
            for(size_t j=i+1;j<fac.size();j++)
            {
                int ta=fac[i].first,tb=fac[j].first,tc=tn/ta/tb;
                if(tc>1 && tc!=ta && tc!=tb)a=ta,b=tb,c=tc;
            }
        if(!a)printf("NO\n");
        else printf("YES\n%d %d %d\n",a,b,c);
    }
    return 0;
}
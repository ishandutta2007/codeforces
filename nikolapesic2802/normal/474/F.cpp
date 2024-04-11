#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
int calc(int a,int b)
{
    if(a==0)
        return b;
    return calc(b%a,a);
}
struct SegmentTree{
    int n;
    vector<int> minn,gcd,broj;
    void init(int nn){
        n=nn;
        minn.resize(2*n);
        gcd.resize(2*n);
        broj.resize(2*n);
    }
    void Set(int p,int f)
    {
        p+=n;
        minn[p]=f;
        gcd[p]=f;
        broj[p]=1;
        p>>=1;
        for(;p>=1;p>>=1)
        {
            if(minn[p*2]>minn[p*2+1])
            {
                minn[p]=minn[p*2+1];
                broj[p]=broj[p*2+1];
            }
            if(minn[p*2]<minn[p*2+1])
            {
                minn[p]=minn[p*2];
                broj[p]=broj[p*2];
            }
            if(minn[p*2]==minn[p*2+1])
            {
                minn[p]=minn[p*2+1];
                broj[p]=broj[p*2+1]+broj[p*2];
            }
            gcd[p]=calc(gcd[p*2],gcd[p*2+1]);
        }
    }
    pair<int,pair<int,int> > Get(int l,int r)
    {
        int m=INT_MAX,g=-1,br=0;
        for(l+=n,r+=n;l<=r;l>>=1,r>>=1)
        {
            if(l%2==1)
            {
                if(m>minn[l])
                {
                    br=broj[l];
                    m=minn[l];
                }
                else
                {
                    if(m==minn[l])
                    {
                        br+=broj[l];
                    }
                }
                if(g==-1)
                    g=gcd[l];
                else
                    g=calc(g,gcd[l]);
                l++;
            }
            if(r%2==0)
            {
                if(m>minn[r])
                {
                    br=broj[r];
                    m=minn[r];
                }
                else
                {
                    if(m==minn[r])
                    {
                        br+=broj[r];
                    }
                }
                if(g==-1)
                    g=gcd[r];
                else
                    g=calc(g,gcd[r]);
                r--;
            }
        }
        return make_pair(m,make_pair(g,br));
    }

} ST;
int main()
{
    int n;
    scanf("%i",&n);
    ST.init(n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        ST.Set(i,a);
    }
    int m;
    scanf("%i",&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        pair<int,pair<int,int> > p = ST.Get(a,b);
        int m=p.first;
        int g=p.second.first;
        int br=p.second.second;
        if(m>g)
        {
            br=0;
        }
        if(m<g)
        {
            printf("ERROR!\n");
            while(true)
            {

            }
        }
        printf("%i\n",b-a+1-br);
    }
    return 0;
}
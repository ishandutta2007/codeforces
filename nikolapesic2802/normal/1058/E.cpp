#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N=30e5+50;
int b[N],even[N],odd[N],prefix[N];
int main()
{
    int n;
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
        ll a;
        scanf("%lld",&a);
        //b[i]=__builtin_popcount(a);
        //printf("%i\n",b[i]);
        int test=0;
        while(a)
        {
            test+=a&1;
            a=a>>1;
        }
        b[i]=test;
        //printf("test: %i\n",test);
    }
    for(int i=0;i<n;i++)
        prefix[i+1]=prefix[i]+b[i];
    /*for(int i=0;i<=n;i++)
    {
        printf("prefix:%i %i\n",i,prefix[i]);
    }*/
    for(int i=0;i<n;i++)
    {
        even[i+1]=even[i]+(prefix[i+1]%2==0);
        odd[i+1]=odd[i]+(prefix[i+1]%2);
    }
    /*for(int i=0;i<=n;i++)
    {
        printf("%i: Even:%i odd:%i\n",i,even[i],odd[i]);
    }*/
    ll res=0;
    for(int i=0;i<n;i++)
    {
        if(prefix[i]%2==0)
            res+=even[n]-even[i+1];
        else
            res+=odd[n]-odd[i+1];
    }
    for(int i=0;i<n;i++)
    {
        int maxx=b[i];
        int sum=b[i];
        for(int j=i+1;j<n&&j-i<65;j++)
        {
            maxx=max(maxx,b[j]);
            sum+=b[j];
            if(sum%2==0&&maxx>sum-maxx)
            {
                res--;
                //printf("Oduzeo! %i %i  %i %i\n",i,j,sum,maxx);
            }
        }
    }
    printf("%lld\n",res);
    return 0;
}
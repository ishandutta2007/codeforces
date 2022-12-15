#include<cstdio>
#include<cstring>

int n;
long long u[1000001],d[1000001],ans,uu,dd,l,r,ll,rr; 
char s[1000001];

int main()
{
    scanf("%d\n",&n);
    for (int i=0; i<n; i++) s[i]=getchar();
    uu=dd=0;
    for (int i=0; i<n; i++)
        if (s[i]=='U') u[uu++]=i; else d[dd++]=i;
    for (int i=1; i<uu; i++) u[i]+=u[i-1];
    for (int i=1; i<dd; i++) d[i]+=d[i-1];
    l=0; r=dd;
    for (int i=0; i<n; i++)
    {
        ans=0; ll=rr=0;
        if (s[i]=='D') 
        {
        	r--;
            if (l<=r) ans+=i+1,ll=l,rr=l;
            else ans+=n-i,ll=r+1,rr=r;
        }
        else
        {
            if (l<r) ans+=i+1,ll=l,rr=l+1;
            else ans+=n-i,ll=r,rr=r;
        }
        if (ll)
        {
            if (l-ll>0) ans+=(ll*i-u[l-1]+u[l-1-ll])<<1;
            else ans+=(ll*i-u[l-1])<<1;
        }
        if (rr)
        {
            if (dd-r>0) ans+=(d[dd+rr-r-1]-d[dd-r-1]-rr*i)<<1;
            else ans+=(d[dd+rr-r-1]-rr*i)<<1;
        }
        if (s[i]=='U') l++;
        printf("%I64d ",ans);
    }
    return 0;
}
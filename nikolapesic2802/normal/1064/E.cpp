#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
bool ask(int x,int y)
{
    printf("%i %i\n",x,y);
    string s;
    cin >> s;
    //fflush(stdout);
    if(s[0]=='b')
        return false;
    return true;
}
int main()
{
    int n;
    scanf("%i",&n);
    //fflush(stdout);
    int l=0,r=1e9;
    int prvo,drugo;
    if(ask(l,(l+r)/2))
        prvo=1;
    else
        prvo=0;
    if(n==1)
    {
        printf("%i %i %i %i\n",r,r,r,0);
        return 0;
    }
    if(ask((l+r)/2,l))
        drugo=1;
    else
        drugo=0;
    int tr=3;
    if(prvo==drugo)
    {
        if(n==2)
        {
            printf("%i %i %i %i\n",r,l,l,r);
            return 0;
        }
        if(ask(r,l)==prvo)
        {
            int x=r;
            int yl=l;
            int yr=(l+r)/2;
            int mid=(yl+yr)/2;
            while(tr<n)
            {
                if(ask(x,mid)==prvo)
                {
                    yl=mid;
                }
                else
                {
                    yr=mid;
                }
                mid=(yl+yr)/2;
                tr++;
            }
            printf("%i %i %i %i\n",(l+r)/2,(l+r)/2,x,mid);
        }
        else
        {
            int xl=(l+r)/2;
            int xr=r;
            int y=0;
            int mid=(xl+xr)/2;
            while(tr<n)
            {
                if(ask(mid,y)==prvo)
                {
                    xl=mid;
                }
                else
                {
                    xr=mid;
                }
                mid=(xl+xr)/2;
                tr++;
            }
            printf("%i %i %i %i\n",(l+r)/2,(l+r)/2,mid,y);
        }
    }
    else
    {
        if(n==2)
        {
            printf("%i %i %i %i\n",l,l,r,r);
            return 0;
        }
        if(ask(l,l)==prvo)
        {
            int xl=l;
            int xr=(l+r)/2;
            int y=0;
            int mid=(xl+xr)/2;
            while(tr<n)
            {
                if(ask(mid,y)==prvo)
                {
                    xl=mid;
                }
                else
                {
                    xr=mid;
                }
                mid=(xl+xr)/2;
                tr++;
            }
            printf("%i %i %i %i\n",(l+r)/2,(l+r)/2,mid,y);
        }
        else
        {
            int x=l;
            int yl=l;
            int yr=(l+r)/2;
            int mid=(yl+yr)/2;
            while(tr<n)
            {
                if(ask(x,mid)==prvo)
                {
                    yr=mid;
                }
                else
                {
                    yl=mid;
                }
                mid=(yl+yr)/2;
                tr++;
            }
            printf("%i %i %i %i\n",(l+r)/2,(l+r)/2,x,mid);
        }
    }
    return 0;
}
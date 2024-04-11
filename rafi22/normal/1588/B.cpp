#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int ask(int l,int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    int x;
    cin>>x;
    return x;
}
int n;
int bs(int x)
{
    int l=1,r=n,sr;
    while(l<=r)
    {
        sr=(l+r)/2;
        if(sr*(sr-1)/2==x) return sr;
        if(sr*(sr-1)/2>x) r=sr-1;
        else l=sr+1;
    }
    return -1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        cin>>n;
        int all=ask(1,n);
        int l=1,r=n,sr;
        int i=-1,k=-1,j;
        while(l<=r)
        {
            sr=(l+r)/2;
            int x;
            if(k!=-1)
            {
                x=ask(sr,n);
                if(x==all) l=sr+1;
                else if(x==0) r=sr-1;
                else
                {
                    int y=bs(x);
                    if(y==-1)
                    {
                        j=sr;
                        l=sr+1;
                    }
                    else
                    {
                        if(sr+y-1==k) r=sr-1;
                        else
                        {
                            j=sr;
                            l=sr+1;
                        }
                    }
                }
            }
            else
            {
                x=ask(1,sr);
                if(x==all) r=sr-1;
                else if(x==0) l=sr+1;
                else
                {
                    int y=bs(x);
                    if(y==-1) r=sr-1;
                    else if(i==-1&&k==-1)
                    {
                        int ni=inf,ni1=-inf;
                        int x1=ask(1,sr-1);
                        int y1=bs(x1);
                        if(y!=-1) ni=sr-y+1;
                        if(y1!=-1) ni1=sr-1-y1+1;
                        if(ni==ni1)
                        {
                            i=ni;
                            l=sr+1;
                            j=sr;
                        }
                        else
                        {
                            x1=ask(sr,n);
                            r=sr-1;
                            //cout<<x1<<" "<<bs(x1)<<endl;
                            k=sr+bs(x1)-1;
                        }
                    }
                    else if(i!=-1)
                    {
                        if(sr-y+1==i)
                        {
                            j=sr;
                            l=sr+1;
                        }
                        else r=sr-1;
                    }
                    else return 2137;
                }
            }
        }
        j++;
        int x=ask(1,j-1);
        i=j-1-bs(x)+1;
        x=ask(j,n);
        k=j+bs(x)-1;
        cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
    }

    return 0;
}
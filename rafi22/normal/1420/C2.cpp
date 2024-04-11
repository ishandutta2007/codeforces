#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;
int tab[300007];
bool add[300007];
bool sub[300007];
int ans;

void check(int a)
{
    if(add[a])
    {
        if(!(tab[a-1]<tab[a]&&tab[a+1]<tab[a]))
        {
            add[a]=0;
            ans-=tab[a];
        }
    }
    else if(tab[a-1]<tab[a]&&tab[a+1]<tab[a])
    {
        add[a]=1;
        ans+=tab[a];
    }
    if(sub[a])
    {
        if(!(tab[a-1]>tab[a]&&tab[a+1]>tab[a]))
        {
            sub[a]=0;
            ans+=tab[a];
        }
    }
    else if(tab[a-1]>tab[a]&&tab[a+1]>tab[a])
    {
        ans-=tab[a];
        sub[a]=1;
    }


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
        ans=0;
        int n,q,a,b;
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=1;i<=n;i++)
        {
            check(i);
        }
        cout<<ans<<endl;
        for(int i=0;i<q;i++)
        {
            cin>>a>>b;
            if(add[a])
            {
                ans-=tab[a];
                add[a]=0;
            }
            else if(sub[a])
            {
                ans+=tab[a];
                sub[a]=0;
            }
            if(add[b])
            {
                ans-=tab[b];
                add[b]=0;
            }
            else if(sub[b])
            {
                ans+=tab[b];
                sub[b]=0;
            }
          //  cout<<ans<<endl;
            swap(tab[a],tab[b]);
            if(a!=n) check(a+1);
            if(a!=1) check(a-1);
            if(b!=n) check(b+1);
            if(b!=1) check(b-1);
            check(a);
            check(b);
            cout<<ans<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            tab[i]=0;
            sub[i]=0;
            add[i]=0;
        }
    }

    return 0;
}
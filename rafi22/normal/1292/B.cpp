#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;


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
        vector<pair<int,int>>p;
        int x0,y0,ax,ay,bx,by,xs,ys,t,T;
        cin>>x0>>y0>>ax>>ay>>bx>>by;
        while(x0<=20000000000000000&&y0<=20000000000000000)
        {
            p.pb({x0,y0});
            x0=ax*x0+bx;
            y0=ay*y0+by;
        }
        cin>>xs>>ys>>T;
        int ans=0;
        for(int i=0;i<sz(p);i++)
        {
            t=T;
            t-=abs(xs-p[i].st)+abs(ys-p[i].nd);
            for(int j=i;j<sz(p);j++)
            {
                for(int l=i;l>=0;l--)
                {
                    if(j>i)
                    {
                        if(2*(abs(p[i].st-p[l].st)+abs(p[i].nd-p[l].nd))+abs(p[i].st-p[j].st)+abs(p[i].nd-p[j].nd)<=t) ans=max(ans,1+j-l);
                    }
                    else
                    {
                        if((abs(p[i].st-p[l].st)+abs(p[i].nd-p[l].nd))+abs(p[i].st-p[j].st)+abs(p[i].nd-p[j].nd)<=t) ans=max(ans,1+j-l);
                    }
                    if(l<i)
                    {
                        if(2*(abs(p[i].st-p[j].st)+abs(p[i].nd-p[j].nd))+abs(p[i].st-p[l].st)+abs(p[i].nd-p[l].nd)<=t) ans=max(ans,1+j-l);
                    }
                    else
                    {
                        if((abs(p[i].st-p[j].st)+abs(p[i].nd-p[j].nd))+abs(p[i].st-p[l].st)+abs(p[i].nd-p[l].nd)<=t) ans=max(ans,1+j-l);
                    }
                }
            }
        }
        cout<<ans;
    }

    return 0;
}
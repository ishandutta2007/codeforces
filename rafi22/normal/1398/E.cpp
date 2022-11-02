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

pair<int,int> seg[2200007];
int pot=1;
map<int,int>nr0;
map<int,int>nr1;

pair<int,int> que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(l>b||r<a) return {0,0};
    pair<int,int> p1=que(2*v,a,b,l,(l+r)/2);
    pair<int,int> p2=que(2*v+1,a,b,(l+r)/2+1,r);
    return {p1.st+p2.st,p1.nd+p2.nd};
}

void ins(int i,int v)
{
    int y=i+pot-1;
    seg[y]={1,v};
    while(y>1)
    {
        y/=2;
        seg[y]={seg[2*y].st+seg[2*y+1].st,seg[2*y].nd+seg[2*y+1].nd};
    }
}
void era(int i)
{
    int y=i+pot-1;
    seg[y]={0,0};
    while(y>1)
    {
        y/=2;
        seg[y]={seg[2*y].st+seg[2*y+1].st,seg[2*y].nd+seg[2*y+1].nd};
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
        int n;
        cin>>n;
        vector<pair<bool,int>>q;
        vector<pair<int,bool>>xd;
        for(int i=1;i<=n;i++)
        {
            bool b;
            int a;
            cin>>b>>a;
            q.pb({b,a});
            if(a>0) xd.pb({a,b});
        }
        sort(xd.begin(),xd.end());
          for(int i=0;i<sz(xd);i++)
        {
            if(xd[i].nd==0) nr0[xd[i].st]=i+1;
            else nr1[xd[i].st]=i+1;
        }
        while(pot<sz(xd)) pot*=2;
        int L=0,sum=0;
        set<int> mini;
        for(auto x:q)
        {
            sum+=x.nd;
            if(x.st==1)
            {
                if(x.nd>0)
                {
                    L++;
                    if(sz(mini)>0)
                    {
                        if(x.nd<*mini.begin()) ins(nr1[*mini.begin()],*mini.begin());
                        else ins(nr1[x.nd],x.nd);
                    }
                    mini.insert(x.nd);
                }
                else
                {
                    L--;
                    x.nd=-x.nd;

                    if(x.nd==*mini.begin())
                    {
                        mini.erase(x.nd);
                        if(sz(mini)>0) era(nr1[*mini.begin()]);
                    }
                    else
                    {
                        mini.erase(x.nd);
                        era(nr1[x.nd]);
                    }
                }
            }
            else
            {
                if(x.nd>0) ins(nr0[x.nd],x.nd);
                else
                {
                    x.nd=-x.nd;
                    era(nr0[x.nd]);
                }
            }
            int l=1,r=sz(xd),sr,ans=0;
            while(l<=r)
            {
                sr=(l+r)/2;
                pair<int,int>p=que(1,sr,sz(xd),1,pot);
                if(p.st<=L)
                {
                    ans=p.nd;
                    r=sr-1;
                }
                else l=sr+1;
            }
            cout<<sum+ans<<endl;
        }
    }

    return 0;
}
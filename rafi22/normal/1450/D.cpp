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

const bool multi=1;

int a[300007];
vector<int> vec[300007];
int seg[1200007],pot;
int rf[300007];
int lf[300007];
bool ans[300007];
int la[300007];
int que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(l>b||r<a) return 0;
    return max(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
}
void ins(int i,int v)
{
    int y=i+pot-1;
    while(y>0)
    {
        seg[y]=v;
        y/=2;
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
        pot=1;
        while(pot<n) pot*=2;
        set<int> s;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            s.insert(a[i]);
            vec[a[i]].pb(i);
        }
        for(int i=1;i<=n;i++)
        {
            lf[i]=que(1,1,a[i]-1,1,pot);
            ins(a[i],i);
        }
        for(int i=0;i<=2*pot;i++) seg[i]=0;
        for(int i=n;i>0;i--)
        {
            rf[i]=n-que(1,1,a[i]-1,1,pot)+1;
            ins(a[i],n-i+1);
        }
        int res=0,res1=0;
        for(int i=1;i<=n;i++)
        {
            int mxi=0,kon=0;
            set<int> s1;
            for(int l=0;l<vec[i].size();l++)
            {
                int j=vec[i][l];
                if(j<kon) continue;
                int d=rf[j]-lf[j]-1;
                la[i]=max(la[i],d);
                if((rf[j]!=j+1&&lf[j]!=j-1)||(l+1!=vec[i].size()&&vec[i][l+1]<rf[j]))
                {
                    res=max(res,d-1);
                    if(s1.count(d)||mxi>=d) ans[d]=1;
                    s1.insert(d);
                }
                else
                {
                    if(d>mxi)
                    {
                        res1=max(res1,mxi);
                        mxi=d;
                    }
                    else res1=max(res1,d);
                }
                kon=rf[j];
            }
            for(auto x:s1) if(x<=mxi) ans[x]=1;
        }
        if(s.size()!=n) cout<<0;
        else cout<<1;
        int maxi=0;
        for(int i=n;i>0;i--)
        {
            if(maxi>=n-i+1) ans[n-i+1]=1;
            maxi=max(maxi,la[i]);
        }
        for(int i=2;i<=n;i++)
        {
            if(i<=res||i<=res1||ans[i]||s.count(1)==0) cout<<0;
            else cout<<1;
        }
        cout<<endl;
        for(int i=0;i<=2*pot;i++) seg[i]=0;
        for(int i=1;i<=n;i++)
        {
            ans[i]=0;
            vec[i].clear();
            la[i]=0;
        }
    }

    return 0;
}
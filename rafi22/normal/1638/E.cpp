#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define mp make_pair
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

unordered_map<int,int>pref;

const int pot=1<<20;

int t[2*pot+7];

void upd(int v,int a,int b,int l,int r,int x)
{
    if(r<a||l>b) return ;
    if(a<=l&&b>=r)
    {
        t[v]+=x;
        return ;
    }
    upd(2*v,a,b,l,(l+r)/2,x);
    upd(2*v+1,a,b,(l+r)/2+1,r,x);
}
int que(int v)
{
    v+=pot-1;
    int ans=0;
    while(v)
    {
        ans+=t[v];
        v/=2;
    }
    return ans;
}

struct seg
{
    int l,r,c,p;
};
bool operator<(const seg &a, const seg &b)
{
    if(a.l==b.l) return a.r<b.r;
    return a.l<b.l;
}
set<seg>S;

void usun(seg x)
{
    S.erase(x);
    upd(1,x.l,x.r,1,pot,pref[x.c]-x.p);
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
        int n,q;
        cin>>n>>q;
        S.insert({1,n,1,0});
        S.insert({-inf,-inf,0,0});
        S.insert({inf,inf,0,0});
        while(q--)
        {
            string s;
            cin>>s;
            int l,r,c;
            if(s=="Color")
            {
                cin>>l>>r>>c;
                seg x=*--S.lower_bound({l,0,0,0});
                if(x.r>=l)
                {
                    S.insert({x.l,l-1,x.c,pref[x.c]});
                    if(x.r>r) S.insert({r+1,x.r,x.c,pref[x.c]});
                    usun(x);
                }
                while(true)
                {
                    seg x=*S.lower_bound({l,0,0,0});
                    if(x.l>r) break;
                    if(x.r>r) S.insert({r+1,x.r,x.c,pref[x.c]});
                    usun(x);
                }
                S.insert({l,r,c,pref[c]});
            }
            if(s=="Add")
            {
                cin>>c>>l;
                pref[c]+=l;
            }
            if(s=="Query")
            {
                cin>>l;
                seg x=*--S.upper_bound({l,inf,inf,inf});
                cout<<que(l)+pref[x.c]-x.p<<endl;
            }
        }
    }

    return 0;
}
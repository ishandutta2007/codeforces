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

int seg[4000007],pot=1;
int pref[1000007];

int que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(r<a||l>b) return inf;
    return min(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
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
        string s;
        cin>>s;
        while(pot<sz(s)) pot*=2;
        s='#'+s;
        for(int i=1;i<sz(s);i++)
        {
            seg[i+pot-1]=seg[i+pot-2];
            pref[i]=pref[i-1];
            if(s[i]=='(')
            {
                seg[i+pot-1]++;
                pref[i]++;
            }
            else seg[i+pot-1]--;
        }
        for(int i=pot-1;i>0;i--) seg[i]=min(seg[2*i],seg[2*i+1]);
        int q;
        cin>>q;
        while(q--)
        {
            int l,r,x,y,z;
            cin>>l>>r;
            x=que(1,l,r,1,pot)-(pref[l-1]-(l-1-pref[l-1]));
          //  cout<<x<<" "<<y<<" "<<z<<endl;
            y=pref[r]-pref[l-1];
            z=(r-l+1)-y;
            if(z>y) x+=(z-y);
            cout<<2*(min(y,z)+min(0LL,x))<<endl;
        }
    }

    return 0;
}
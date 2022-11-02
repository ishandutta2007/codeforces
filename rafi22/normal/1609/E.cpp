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
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

struct S
{
    int maxP=0;
    int maxS=0;
    int opt=0;
    int ca=0;
    int cb=0;
    int cc=0;
};

S seg[4*100007];
int pot=1<<17;

S Merge(S L,S R)
{
    return {max(L.maxP,L.cc-L.cb+R.maxP),max(R.maxS,R.ca-R.cb+L.maxS),min({L.opt+R.cc,R.opt+L.ca,L.ca-L.maxS+R.cc-R.maxP}),L.ca+R.ca,L.cb+R.cb,L.cc+R.cc};
}
void ins(int v,char x)
{
    v+=pot-1;
    S ne;
    if(x=='a')
    {
        ne.ca++;
        ne.maxS=1;
    }
    if(x=='b') ne.cb++;
    if(x=='c')
    {
        ne.cc++;
        ne.maxP=1;
    }
    seg[v]=ne;
    while(v>1)
    {
        v/=2;
        seg[v]=Merge(seg[2*v],seg[2*v+1]);
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
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        s='#'+s;
        for(int i=1;i<=n;i++) ins(i,s[i]);
        while(q--)
        {
            int p;
            char c;
            cin>>p>>c;
            ins(p,c);
            cout<<seg[1].opt<<endl;
        }
    }

    return 0;
}
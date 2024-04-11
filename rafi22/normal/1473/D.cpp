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

int L[200007];
int R[200007];
int P[200007];
int L1[200007];
int R1[200007];

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
        int a=0,l=0,p=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='+') a++;
            else a--;
            l=min(l,a);
            p=max(p,a);
            L[i]=l;
            R[i]=p;
            P[i]=a;
        }
        a=0,l=0,p=0;
        for(int i=n;i>0;i--)
        {
            if(s[i]=='+') a++;
            else a--;
            L1[i]=a-p;
            R1[i]=a-l;
            l=min(l,a);
            p=max(p,a);
        }
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            cout<<max(R[x-1],R1[y+1]+P[x-1])-min(L[x-1],L1[y+1]+P[x-1])+1<<endl;
        }
        for(int i=0;i<=n+1;i++)
        {
            L[i]=0;
            R[i]=0;
            P[i]=0;
            L1[i]=0;
            R1[i]=0;
        }
    }

    return 0;
}
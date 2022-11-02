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

const bool multi=0;

deque <int> pos[26];
int tree[1000007];
int querry(int v,int a,int b,int p,int k)
{
    if(a<=p&&k<=b) return tree[v];
    if(p>b||k<a) return 0;
    return querry(2*v,a,b,p,(p+k)/2)+querry(2*v+1,a,b,(p+k)/2+1,k);
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
        int n,ans=0,pot=1;
        cin>>n;
        string str;
        cin>>str;
        while(pot<str.size()) pot*=2;
        for(int i=str.size()-1;i>=0;i--) pos[str[i]-97].pb(str.size()-i);
        for(int i=0;i<str.size();i++)
        {
            int y=pos[str[i]-97][0];
            pos[str[i]-97].pop_front();
            ans+=querry(1,y+1,n,1,pot);
            y=y+pot-1;
            tree[y]++;
            while(y>1)
            {
                y/=2;
                tree[y]=tree[2*y]+tree[2*y+1];
            }
        }
        cout<<ans;
    }

    return 0;
}
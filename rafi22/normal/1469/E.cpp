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
set<int>zbior;
int last[1000007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<(1<<20);i++) zbior.insert(i);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        s='#'+s;
        int l=min((int)20,k);
        vector<int> masks;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0') last[i]=i;
            else last[i]=last[i-1];
        }
        for(int i=1;i<=n-l+1;i++)
        {
            int it=l-1,m=0;
            if(i-1-last[i-1]>=k-l)
            {
                for(int j=i; j<i+l; j++)
                {
                    if(s[j]=='0') m+=(1<<it);
                    it--;
                }
                masks.pb(m);
            }
        }
        for(auto m:masks) zbior.erase(m);
        if(*zbior.begin()>=(1<<l)) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=0;i<k-l;i++) cout<<'0';
            int it=l-1,a=*zbior.begin();
            for(int i=0;i<l;i++)
            {
                if((a&(1<<it))) cout<<'1';
                else cout<<'0';
                it--;
            }
            cout<<endl;
        }
        for(auto m:masks) zbior.insert(m);
    }

    return 0;
}
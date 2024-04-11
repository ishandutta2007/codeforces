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

int ile1[27],ile2[27];

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
        int n,k;
        cin>>n>>k;
        string a,b;
        cin>>a>>b;
        for(auto x:a) ile1[x-'a']++;
        for(auto x:b) ile2[x-'a']++;
        bool ok=1;
        for(int i=0;i<26;i++)
        {
            if(ile2[i]>ile1[i]) ok=0;
            ile1[i]-=ile2[i];
            if(ile1[i]%k!=0) ok=0;
            ile1[i+1]+=ile1[i];
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        for(int i=0;i<26;i++)
        {
            ile1[i]=0;
            ile2[i]=0;
        }
    }

    return 0;
}
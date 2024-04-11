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

const bool multi=1;

int ile[26];

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
        string s;
        cin>>s;
        for(int i=0;i<26;i++) ile[i]=0;
        for(auto x:s) ile[x-'a']++;
        int c=0;
        for(int i=0;i<26;i++) c+=ile[i]%2;
        n-=max(0LL,c-k);
    //    cout<<n<<" "<<c<<" "<<k<<endl;
        int d=(n-min(k,c))/2;
     //   cout<<d<<endl;
        if(d==0) cout<<1<<endl;
        else
        {
            int x=d/k;
            int ile=min(c,k)+d%k;
            if(k-d%k>ile) cout<<2*x<<endl;
            else cout<<2*x+1<<endl;
        }
    }

    return 0;
}
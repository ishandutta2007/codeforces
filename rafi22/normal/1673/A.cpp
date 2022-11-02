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
        int n=sz(s);
        int sum=0;
        for(int i=0;i<sz(s);i++) sum+=s[i]-'a'+1;
        if(n%2==0) cout<<"Alice "<<sum<<endl;
        else
        {
            int a=sum-min(s[0],s.back())+'a'-1,b=min(s[0],s.back())-'a'+1;
            if(a>b) cout<<"Alice "<<a-b<<endl;
            else cout<<"Bob "<<b-a<<endl;
        }
    }

    return 0;
}
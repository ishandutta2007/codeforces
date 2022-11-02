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

int flip[200007];

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
        memset(flip,0,sizeof flip);
        int n,k,c=0,last;
        cin>>n>>k;
        string s,ans="";
        cin>>s;
        for(int i=0;i<n;i++)
        {
            int x=(s[i]-'0')^(k%2);
            if(x==0&&c<k)
            {
                c++;
                flip[i]=1;
            }

        }
        if(c%2!=k%2)
        {
            flip[n-1]++;
            c++;
        }
        flip[n-1]+=(k-c);
        for(int i=0;i<n;i++)
        {
            int x=(s[i]-'0')^(k%2)^(flip[i]%2);
            cout<<x;
        }
        cout<<endl;
        for(int i=0;i<n;i++) cout<<flip[i]<<" ";
        cout<<endl;
    }

    return 0;
}
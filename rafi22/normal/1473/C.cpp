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

int a[200007];
int silnia[25];

signed main()
{
    silnia[0]=1;
    for(int i=1;i<20;i++) silnia[i]=silnia[i-1]*i;
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
        vector<int>v;
        for(int i=1;i<=(k-1)-(n-k);i++) cout<<i<<" ";
        for(int i=k;i>(k-1)-(n-k);i--) cout<<i<<" ";
        cout<<endl;

        /*for(int i=1;i<=k;i++) v.pb(i);
        while(true)
        {
            int inv=0;
            for(int i=0;i<sz(v);i++)
            {
                for(int j=(k-1)-(n-k);j<i;j++) if(v[j]<v[i]) inv++;
                for(int j=i+1;j<sz(v)-1;j++) if(v[j]<v[i]) inv+=2;
                if(i!=sz(v)-1) if(v[sz(v)-1]<v[i]) inv++;
            }
            if(inv>(n-k)*(n-k))
            {

                break;
            }
            if(!next_permutation(v.begin(),v.end())) break;
        }
        prev_permutation(v.begin(),v.end());
        for(auto x:v) cout<<x<<" ";
        cout<<endl;*/


    }

    return 0;
}
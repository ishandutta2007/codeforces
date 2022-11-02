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

vector<int>v[17];
vector<vector<int>>ban;

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
        int n,k,a,s=0,m;
        cin>>n;
        vector<int>b(n);
        for(int i=0;i<n;i++)
        {
            cin>>k;
            b[i]=k;
            while(k--)
            {
                cin>>a;
                v[i].pb(a);
            }
            s+=v[i].back();
        }
        cin>>m;
        while(m--)
        {
            vector<int>bb(n);
            for(int i=0;i<n;i++) cin>>bb[i];
            ban.pb(bb);
        }
        int ans=0;
        vector<int>aV;
        sort(all(ban));
        if(!binary_search(all(ban),b))
        {
            ans=s;
            aV=b;
        }
        for(auto B:ban)
        {
            s=0;
            for(int i=0;i<n;i++) s+=v[i][B[i]-1];
            for(int i=0;i<n;i++)
            {
                if(B[i]>1)
                {
                    B[i]--;
                    if(!binary_search(all(ban),B))
                    {
                        if(s-v[i][B[i]]+v[i][B[i]-1]>ans)
                        {
                            ans=s-v[i][B[i]]+v[i][B[i]-1];
                            aV=B;
                        }
                    }
                    B[i]++;
                }
            }
        }
        for(int i=0;i<n;i++) cout<<aV[i]<<" ";
    }

    return 0;
}
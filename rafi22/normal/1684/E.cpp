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

map<int,int>M;
int P[200007];

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
        M.clear();
        int n,k,x;
        cin>>n>>k;
        set<int>S;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            S.insert(x);
            M[x]++;
        }
        for(int i=1;i<=n-1;i++) P[i]=P[i-1]+(M[i-1]==0);
        int ans=inf,sum=0;
        priority_queue<int>Q;
        int t=0;
        for(auto x:S)
        {
            if(x<n) continue;
            t++;
            if(sum+M[x]<=k)
            {
                Q.push(M[x]);
                sum+=M[x];
            }
            else if(sz(Q)>0&&M[x]<Q.top())
            {
                sum-=Q.top();
                Q.pop();
                Q.push(M[x]);
                sum+=M[x];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(P[i]<=k) ans=min(ans,t-sz(Q));
            if(M[i]>0)
            {
                t++;
                if(sum+M[i]<=k)
                {
                    Q.push(M[i]);
                    sum+=M[i];
                }
                else if(sz(Q)>0&&M[i]<Q.top())
                {
                    sum-=Q.top();
                    Q.pop();
                    Q.push(M[i]);
                    sum+=M[i];
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
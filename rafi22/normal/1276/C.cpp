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

const int N=400007;

vector<int>d[N];
map<int,int>ile;
int row[N];
vector<int>ans[N];

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
        for(int i=1;i<=400000;i++)
        {
            for(int j=i;j<=400000;j+=i)
            {
                if(i>=j/i) d[j].pb(i);
            }
        }
        int n,x;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            ile[x]++;
        }
        priority_queue<pair<int,int>>Q;
        for(auto x:ile) Q.push({x.nd,x.st});
        for(int i=n;i>0;i--)
        {
            for(auto a:d[i])
            {
                int b=i/a;
                if(b>=Q.top().st)
                {
                    cout<<i<<endl;
                    swap(a,b);
                    cout<<a<<" "<<b<<endl;
                    for(int i=0;i<a;i++) ans[i].resize(b);
                    int X=0,Y=0;
                    while(sz(Q)>0)
                    {
                        int l=Q.top().st,x=Q.top().nd;
                        Q.pop();
                        for(int j=0;j<l;j++)
                        {
                            ans[X][Y%b]=x;
                           // cout<<X<<" "<<Y<<endl;
                            X++;
                            Y++;
                            if(X==a)
                            {
                                X=0;
                                Y-=a-1;
                            }
                        }
                    }
                    for(int i=0;i<a;i++)
                    {
                        for(int j=0;j<b;j++) cout<<ans[i][j]<<" ";
                        cout<<endl;
                    }
                    return 0;
                }
            }
            int c=Q.top().st,x=Q.top().nd;
            Q.pop();
            ile[x]--;
            if(c>1) Q.push({c-1,x});
        }
    }

    return 0;
}
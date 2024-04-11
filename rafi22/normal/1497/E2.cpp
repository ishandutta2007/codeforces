#include <bits/stdc++.h>

//#define int long long
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

bool p[10000007];
bool is[10000007];
vector<int>fac[10000007];
int id[200007];
int a[200007];
int DP[200007][21];
int last[200007];

bool cmp(int l,int r)
{
    return (lexicographical_compare(fac[a[l]].begin(),fac[a[l]].end(),fac[a[r]].begin(),fac[a[r]].end()));
}

vector<pair<pair<int,int>,vector<int>>>tc;

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
        vector<int>vec;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            is[a[i]]=1;
            vec.pb(a[i]);
        }
        tc.pb({{n,k},vec});
    }
    for(int i=2; i<=10000000; i++)
    {
        if(p[i]) continue;
        fac[i].pb(i);
        for(int j=2*i; j<=10000000; j+=i)
        {
            p[j]=1;
            if(!is[j]) continue;
            int y=j,c=0;
            while(y%i==0)
            {
                c++;
                y/=i;
            }
            if(c%2) fac[j].pb(i);
        }
    }
    for(auto t:tc)
    {
        int n=t.st.st,k=t.st.nd;
        vector<int>vec;
        for(int i=1;i<=n;i++)
        {
            a[i]=t.nd[i-1];
            vec.pb(i);
        }
        sort(vec.begin(),vec.end(),cmp);
        int it=1;
        id[vec[0]]=1;
        for(int i=1;i<sz(vec);i++)
        {
            if(fac[a[vec[i]]]!=fac[a[vec[i-1]]]) it++;
            id[vec[i]]=it;
        }
        set<int>error;
        error.insert(0);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++) DP[i][j]=mod;
            error.insert(last[id[i]]);
            last[id[i]]=i;
            set<int>::iterator w=--error.end();
            for(int j=0;j<=k;j++)
            {
                for(int l=k;l>=0;l--)
                {
                    if(l-j<0) break;
                    DP[i][l]=min(DP[i][l],DP[*w][l-j]+1);
                }
                if(w==error.begin()) break;
                w--;
            }
        }
        cout<<DP[n][min(k,n)]<<endl;
        for(int i=1;i<=it;i++) last[i]=0;
    }


    return 0;
}
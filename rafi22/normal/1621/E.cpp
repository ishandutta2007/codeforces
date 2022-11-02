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

const int N=100007;

int a[N];
vector<int>V[N];
vector<bool>ans[N];

bool cmp(pair<pair<int,int>,int>L,pair<pair<int,int>,int>R)
{
    if(R.st.st==inf) return 1;
    if(L.st.st==inf) return 0;
    return L.st.st*R.st.nd>R.st.st*L.st.nd;
}
set<int>bad[3];
bool check(int l,int r,int c)
{
  //  cout<<"?"<<l<<" "<<r<<" "<<c<<endl;
    if(*bad[c].lower_bound(l)<=r) return 0;
  //  cout<<"ok"<<endl;
    return 1;
}

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
        int n,m;
        cin>>n>>m;
        bad[0].clear();
        bad[1].clear();
        bad[2].clear();
        for(int i=0;i<=n;i++)
        {
            V[i].clear();
            ans[i].clear();
        }
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n,greater<int>());
        vector<pair<pair<int,int>,int>>S;
        S.pb({{inf,1},0});
        for(int i=1;i<=m;i++)
        {
            int k;
            cin>>k;
            V[i].resize(k);
            ans[i].resize(k);
            int s=0;
            for(int j=0;j<k;j++)
            {
                cin>>V[i][j];
                s+=V[i][j];
                ans[i][j]=0;
            }
            S.pb({{s,k},i});
        }
        sort(all(S),cmp);
        bad[0].insert(inf);
        bad[1].insert(inf);
        bad[2].insert(inf);
        for(int i=0;i<m;i++)
        {
            if(i&&S[i].st.st>a[i-1]*S[i].st.nd) bad[0].insert(i);
            if(S[i].st.st>a[i]*S[i].st.nd) bad[1].insert(i);
            if(i!=m-1&&S[i].st.st>a[i+1]*S[i].st.nd) bad[2].insert(i);
        }
        for(int i=0;i<m;i++)
        {
            int id=S[i].nd;
            for(int j=0;j<sz(V[id]);j++)
            {
                pair<pair<int,int>,int>p={{S[i].st.st-V[id][j],S[i].st.nd-1},id};
                int l=upper_bound(all(S),p,cmp)-S.begin();
                if(l>i)
                {
                    if(check(0,i-1,1)&&check(i+1,l-1,0)&&S[i].st.st-V[id][j]<=a[l-1]*(S[i].st.nd-1)&&check(l,m-1,1)) ans[id][j]=1;
                }
                else
                {
                    if(check(0,l-1,1)&&S[i].st.st-V[id][j]<=a[l]*(S[i].st.nd-1)&&check(l,i-1,2)&&check(i+1,m-1,1)) ans[id][j]=1;
                }
            }
        }
        for(int i=1;i<=m;i++) for(auto x:ans[i]) cout<<x;
        cout<<endl;
    }

    return 0;
}
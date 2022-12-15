#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,m,r,sc;
vector<pair<int,string> > v[10004];
string s;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    while(n--)
    {
        cin>>s>>r>>sc;
        r--;
        v[r].pb({-sc,s});
    }
    For(i,0,m)
    {
        sort(v[i].begin(),v[i].end());
        if(v[i].size()>2&&v[i][1].first==v[i][2].first) cout<<"?"<<endl;
        else cout<<v[i][0].second<<' '<<v[i][1].second<<endl;
    }
}
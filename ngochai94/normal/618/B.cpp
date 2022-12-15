#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-8
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,val,ans[55];
vector<int> v[55];
bool flag;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n)
    {
        For(j,0,n)
        {
            cin>>val;
            if(val) v[i].pb(val);
        }
        sort(v[i].begin(),v[i].end());
    }
    flag=false;
    For(i,0,n)
    {
        val=v[i][v[i].size()-1];
        ans[i]=val;
        if(flag&&val==n-1) ans[i]=n;
        if(val==n-1) flag=true;
        cout<<ans[i]<<' ';
    }
}
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

int n,m,q,r[10004],c[10004],x[10004],typ[10004],ans[111][111];


int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>q;
    For(i,0,q)
    {
        cin>>typ[i];
        if(typ[i]==1) cin>>r[i];
        else if(typ[i]==2) cin>>c[i];
        else cin>>r[i]>>c[i]>>x[i];
        r[i]--;c[i]--;
    }
    //cout<<x[5]<<endl;
    while(q--)
    {
        if(typ[q]==1)
        {
            int row = r[q];
            int tmp = ans[row][m-1];
            for(int i=m-1;i>0;i--) ans[row][i] = ans[row][i-1];
            ans[row][0] = tmp;
        }
        else if(typ[q]==2)
        {
            int col = c[q];
            int tmp = ans[n-1][col];
            for(int i=n-1;i>0;i--) ans[i][col] = ans[i-1][col];
            ans[0][col] = tmp;
        }
        else ans[r[q]][c[q]] = x[q];
    }
    For(i,0,n)
    {
        For(j,0,m) cout<<ans[i][j]<<' ';
        cout<<endl;
    }
}
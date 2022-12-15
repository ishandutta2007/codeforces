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

int n,k,ans[555][555];

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    k--;
    int cur=n*n;
    For(i,0,n) for(int j=n-1;j>=k;j--) ans[i][j]=cur--;
    For(i,0,n) for(int j=k-1;j>=0;j--) ans[i][j]=cur--;
    long long ret=0;
    For(i,0,n) ret+=ans[i][k];
    cout<<ret<<endl;
    For(i,0,n)
    {
        For(j,0,n) cout<<ans[i][j]<<' ';
        cout<<endl;
    }
}
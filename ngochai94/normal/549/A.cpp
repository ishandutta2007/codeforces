#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-12
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,m,ans,dx[2]={0,1},dy[2]={0,1};
string s[55];

bool ff(int i,int j)
{
    int f=0,a=0,c=0,e=0;
    For(ii,0,2) For(jj,0,2)
    {
        char cc=s[i+ii][j+jj];
        if(cc=='f') f++;
        else if(cc=='a') a++;
        else if(cc=='c') c++;
        else if(cc=='e') e++;
    }
    return (f==1&&a==1&&c==1&&e==1);
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin>>n>>m;
    For(i,0,n) cin>>s[i];
    ans=0;
    For(i,0,n-1) For(j,0,m-1)
    {
        if(ff(i,j)) ans++;
    }
    cout<<ans;
}
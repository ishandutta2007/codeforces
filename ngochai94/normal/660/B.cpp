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

int n,m;
vector<int> win,nwin;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m;
    For(i,1,n+1)
    {
        if(n*2+i*2-1<=m) cout<<n*2+i*2-1<<' ';
        if(i*2-1<=m) cout<<i*2-1<<' ';
        if(n*2+i*2<=m) cout<<n*2+i*2<<' ';
        if(i*2<=m) cout<<i*2<<' ';
    }
}
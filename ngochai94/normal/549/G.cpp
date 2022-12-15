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

int n,lis[200005],k;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n)
    {
        cin>>k;
        lis[i]=k-n+i;
    }
    sort(lis,lis+n);
    For(i,0,n-1) if(lis[i]==lis[i+1])
    {
        cout<<":(";return 0;
    }
    For(i,0,n) cout<<lis[i]+n-i<<' ';
}
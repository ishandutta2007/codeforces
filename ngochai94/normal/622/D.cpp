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

int n,lis[1000006];

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    scanf("%d",&n);
    for(int i=1;i<n;i+=2) lis[i/2]=lis[n-1-i/2]=i;
    for(int i=2;i<n;i+=2) lis[n+i/2-1]=lis[n+n-i/2-1]=i;
    if(n&1) lis[n/2]=n;
    else lis[n/2+n-1]=n;
    lis[2*n-1]=n;
    For(i,0,2*n) printf("%d ",lis[i]);
}
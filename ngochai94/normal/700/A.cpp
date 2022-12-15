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

double n,l,v1,v2,k;
int N,K;

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>N>>l>>v1>>v2>>K;
    n=(N+K-1)/K;
    cout<<setprecision(11)<<l/(v1+1/(n/(v2-v1)+(n-1)/(v2+v1)));
}
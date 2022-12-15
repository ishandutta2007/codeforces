#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

long long n,x,y,val;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    x=y=0;
    cin>>n;
    For(i,0,n)
    {
        cin>>val;
        x|=val;
    }
    For(i,0,n)
    {
        cin>>val;
        y|=val;
    }
    cout<<x+y;
}
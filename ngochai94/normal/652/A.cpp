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

int n,a,b,h1,h2;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>h1>>h2>>a>>b;
    n=h2-h1-a*8;
    if(n<=0)
    {
        cout<<0;return 0;
    }
    if(a<=b)
    {
        cout<<-1;
        return 0;
    }
    int i=0;
    while(++i)
    {
        n+=b*12;
        n-=a*12;
        if(n<=0)
        {
            cout<<i;return 0;
        }
    }
}
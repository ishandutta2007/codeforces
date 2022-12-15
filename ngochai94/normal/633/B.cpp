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

int m,n;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>m;
    For(i,1,1000000)
    {
        n=5*i;
        // cout<<i<<' '<<n<<endl;
        while(n%5==0)
        {
            n/=5;
            m--;
        }
        if(m<0)
        {
            cout<<0;return 0;
        }
        if(m==0)
        {
            cout<<5<<endl;
            For(j,0,5) cout<<j+5*i<<' ';
            return 0;
        }
    }
    // cout<<m<<endl;
}
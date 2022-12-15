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

int a,b,c;

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>a>>b>>c;
    For(i,0,10000)
    {
        if(c>=i*a&&(c-i*a)%b==0)
        {
        	// cout<<c<<i*a<<endl;
            cout<<"Yes";return 0;
        }
    }
    cout<<"No";
}
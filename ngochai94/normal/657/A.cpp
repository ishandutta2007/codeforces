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

int n,d,h;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>d>>h;
    if(d>2*h||d==1&&n!=2)
    {
        cout<<-1;return 0;
    }
    For(i,1,h+1) cout<<i<<' '<<i+1<<endl;
    d-=h;
    if(d) cout<<1<<' '<<h+2<<endl;
    For(i,1,d) cout<<h+1+i<<' '<<h+2+i<<endl;
    For(i,h+2+d,n+1) cout<<h<<' '<<i<<endl;
}
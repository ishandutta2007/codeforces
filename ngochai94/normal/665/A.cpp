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

int a,ta,b,tb,h,m,ans;
char c;

bool check(int x)
{
    return x>=5*60&&x<24*60&&((x-5*60)%b==0);
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>a>>ta>>b>>tb>>h>>c>>m;
    h=h*60+m;
    For(i,h-tb+1,h+ta) if(check(i)) ans++;
    cout<<ans;
}
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

int h,m,a;
char c;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>h>>c>>m>>a;
    int t=h*60+m+a;
    t%=60*24;
    //cout<<t<<endl;
    h=t/60;
    m=t%60;
    printf("%02d:%02d",h,m);
}
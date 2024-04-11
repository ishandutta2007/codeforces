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

int n,r,b,g;
string s;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>s;
    r=b=g=0;
    for(char c:s)
    {
        if(c=='R') r++;
        else if(c=='G') g++;
        else b++;
    }
    if(!g&&!r||g&&r||b&&g+r>1) cout<<'B';
    if(!b&&!r||b&&r||g&&b+r>1) cout<<'G';
    if(!b&&!g||b&&g||b+g>1&&r) cout<<'R';
}
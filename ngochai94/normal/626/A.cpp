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

int n,ans;
string s;

bool solve(int st,int en)
{
    //cout<<st<<' '<<en<<endl;
    int x=0;
    int y=0;
    For(i,st,en+1)
    {
        if(s[i]=='U') x++;
        if(s[i]=='D') x--;
        if(s[i]=='L') y++;
        if(s[i]=='R') y--;
    }
    //cout<<x<<' '<<y<<endl;
    return x==0&&y==0;
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    ans=0;
    cin>>n>>s;
    For(i,0,n) For(j,i,n) if(solve(i,j)) ans++;
    cout<<ans;
}
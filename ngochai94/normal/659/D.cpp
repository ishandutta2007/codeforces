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

int n,x,y,lx,ly;
string s;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    cin>>lx>>ly;
    For(i,0,n)
    {
        cin>>x>>y;
        if(y>ly) s+='n';
        if(x>lx) s+='e';
        if(y<ly) s+='s';
        if(x<lx) s+='w';
        lx=x;
        ly=y;
    }
    int ans=0;
    For(i,1,n)
    {
        if(s[i]=='n'&&s[i-1]=='e'||s[i]=='w'&&s[i-1]=='n'||s[i]=='s'&&s[i-1]=='w'||s[i]=='e'&&s[i-1]=='s') ans++;
    }
    cout<<ans;
}
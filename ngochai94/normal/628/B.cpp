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

long long n,ans,cur;
string s;


int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>s;
    n=s.size();
    For(i,1,n)
    {
        cur=s[i]-'0';
        cur+=10*(s[i-1]-'0');
        if(cur%4==0) ans+=i;
        if((s[i]-'0')%4==0) ans++;
    }
    if((s[0]-'0')%4==0) ans++;
    cout<<ans;
}
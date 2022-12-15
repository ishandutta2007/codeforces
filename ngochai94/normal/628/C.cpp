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

long long n,k,can;
string s,ans;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>k>>n;
    cin>>s;
    ans="";
    for(char c:s)
    {
        //cout<<n<<endl;
        if(c-'a'>'z'-c)
        {
            if(n<c-'a')
            {
                ans+=c-n;
                n=0;
            }
            else
            {
                n-=c-'a';
                ans+='a';
            }
        }
        else
        {
            if(n<'z'-c)
            {
                ans+=c+n;
                n=0;
            }
            else
            {
                n-='z'-c;
                ans+='z';
            }
        }
    }
    if(n) cout<<-1;
    else cout<<ans;
}
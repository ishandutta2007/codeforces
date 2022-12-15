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

int n,kmp[123456];
string s,ss;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>s>>ss;
    n=ss.size();
    s=ss+' '+s;
    kmp[0]=-1;kmp[1]=0;
    int cur=0;
    For(i,2,s.size()+1)
    {
        while(cur!=-1&&s[i-1]!=s[cur]) cur=kmp[cur];
        cur++;
        kmp[i]=cur;
    }
    //For(i,0,s.size()+1) cout<<kmp[i]<<' ';
    int ans=0;
    For(i,2*n+1,s.size()+1)
    {
        //cout<<i<<' '<<kmp[i]<<' '<<endl;
        if(kmp[i]==n)
        {
            ans++;
            i+=n-1;
        }
    }
    cout<<ans;
}
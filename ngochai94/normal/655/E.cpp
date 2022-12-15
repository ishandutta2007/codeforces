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

long long n,k,cnt[26],all,mark[26];
string s,seq,tmp;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>k>>s;
    For(i,0,26) cnt[i]=1;
    seq="";
    long long ans=1;
    for(char c:s)
    {
        int p=c-'a';
        mark[p]=1;
        long long val=all+cnt[p];
        ans+=val;
        ans%=mod;
        all+=val;
        all%=mod;
        cnt[p]-=val;
        cnt[p]%=mod;
    }
    For(i,0,k) if(!mark[i])
    {
        char c='a'+i;
        seq+=c;
    }
    reset(mark,0);
    tmp="";
    for(int i=s.size()-1;i>=0;i--)
    {
        int p=s[i]-'a';
        if(!mark[p])
        {
            tmp+=s[i];
            mark[p]=1;
        }
    }
    for(int i=tmp.size()-1;i>=0;i--) seq+=tmp[i];
    For(i,0,n)
    {
        char c=seq[i%k];
        int p=c-'a';
        long long val=all+cnt[p];
        ans+=val;
        ans%=mod;
        all+=val;
        all%=mod;
        cnt[p]-=val;
        cnt[p]%=mod;
    }
    cout<<(ans+mod)%mod;
}
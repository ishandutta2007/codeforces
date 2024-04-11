#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

long long n,m,kmp[400005],num,ans;
char c,cc;
pair<long long,char> tt[200005],ss[200005];
vector<pair<long long,char> > t,s,re;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    For(i,0,n)
    {
        cin>>num>>cc>>c;
        tt[i]={num,c};
    }
    For(j,0,m)
    {
        cin>>num>>cc>>c;
        ss[j]={num,c};
    }
    t.pb(tt[0]);
    s.pb(ss[0]);
    For(pos,1,n)
    {
        //cout<<t[t.size()-1].second<<' '<<tt[pos].second<<endl;
        if(t[t.size()-1].second==tt[pos].second)
        {
            t[t.size()-1].first+=tt[pos].first;
        }
        else t.pb(tt[pos]);
    }
    For(pos,1,m)
    {
        if(s[s.size()-1].second==ss[pos].second) s[s.size()-1].first+=ss[pos].first;
        else s.pb(ss[pos]);
    }
    n=t.size();
    m=s.size();
    ans=0;
    //cout<<n<<' '<<m<<endl;
    if(m>n)
    {
        cout<<0;return 0;
    }
    if(m==1)
    {
        for(auto p:t) if(p.second==s[0].second) ans+=max(0ll,1ll+p.first-s[0].first);
        cout<<ans;return 0;
    }
    if(m==2)
    {
        For(i,0,n) if(t[i].second==s[0].second&&t[i+1].second==s[1].second&&t[i].first>=s[0].first&&t[i+1].first>=s[1].first) ans++;
        cout<<ans;return 0;
    }
    For(i,1,m-1) re.pb(s[i]);
    re.pb({-1,'A'});
    For(i,1,n-1) re.pb(t[i]);
    // n+m-3
    kmp[0]=-1;
    kmp[1]=0;
    long long cur=0;
    //for(auto p:t) cout<<p.first<<' '<<p.second<<endl;
    For(len,2,n+m-2)
    {
        while(cur>=0&&re[cur]!=re[len-1]) cur=kmp[cur];
        cur++;
        kmp[len]=cur;
    }
    //For(i,0,n+m-2) cout<<kmp[i]<<' ';cout<<endl;
    For(i,0,n+m-2) if(kmp[i]==m-2)
    {
        // i-m+1
        int l=i-2*m+3,r=l+m-1;
        //cout<<l<<' '<<r<<endl;
        if(t[l].second==s[0].second&&t[r].second==s[m-1].second&&t[l].first>=s[0].first&&t[r].first>=s[m-1].first) ans++;
    }
    cout<<ans;
}
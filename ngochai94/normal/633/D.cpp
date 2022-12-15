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

long long n,cur,last,a[1111],ans,curans;
map<long long,long long> out;
vector<long long> in;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n)
    {
        cin>>a[i];
        out[a[i]]++;
    }
    ans=2;
    if(out.count(0)) ans=max(ans,out[0]);
    if(ans>55)
    {
        cout<<ans;
        return 0;
    }
    //cout<<out.size()<<endl;
    For(i,0,n) For(j,0,n) if(i!=j)
    {
        cur=a[i];last=a[j];
        curans=2;
        out[cur]--;out[last]--;
        in.pb(cur);in.pb(last);
        //cout<<cur+last<<' '<<out.size()<<endl;
        while(out.count(last+cur)&&out[last+cur])
        {
            cur+=last;
            last=cur-last;
            out[cur]--;
            in.pb(cur);
            curans++;
        }
        ans=max(ans,curans);
        for(auto ii:in) out[ii]++;
        in.clear();
        //cout<<ans;return 0;
    }
    cout<<ans;
}
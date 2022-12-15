#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

long long n,m,lis[200005],t,len,ans[200005],dir;
stack<pair<long long, long long> > s;
vector<pair<long long, long long> > v;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    For(i,0,n) cin>>lis[i];
    while(m--)
    {
        cin>>t>>len;
        while(!s.empty()&&s.top().second<=len) s.pop();
        s.push({t,len});
    }
    while(!s.empty())
    {
        v.pb(s.top());
        s.pop();
    }
    reverse(v.begin(),v.end());
    For(i,v[0].second,n) ans[i]=lis[i];
    int l=0,r=v[0].second-1;
    sort(lis,lis+r+1);
    dir=1;
    int pos=r;
    For(i,0,v.size())
    {
        int num;
        if(i==v.size()-1) num=v[i].second;
        else num=v[i].second-v[i+1].second;
        if(v[i].first==1) while(num--) ans[pos--]=lis[r--];
        else while(num--) ans[pos--]=lis[l++];
    }
    For(i,0,n) cout<<ans[i]<<' ';
}
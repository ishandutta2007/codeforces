#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=3e5+10,MAXM=2e6+10,INF=INT_MAX;
const int MOD=1e9+7,mod=998244353;
 
map<int,int> mp;
map<int,int>::iterator it;
vector<pii> v;
int ans[MAXM];
int maxn=0,mx=0,k,zz;
 
int getnum(int i,int j)
{
    return i*k+j;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        mp[p]++;
    }
    for(it=mp.begin();it!=mp.end();it++)
    v.push_back({it->second,it->first});
    sort(v.begin(),v.end(),greater<pii>());
 
    for(int i=1;i<=min((int)sqrt(n),(int)v.size());i++)
    {
        int s=0;
        for(auto j:v)
        {
            s+=min(i,j.first);
        }
        s=s/i*i;
        if(s>maxn&&s/i>=i)
        {
            maxn=s;
            mx=i;
        }
    }
    k=maxn/mx,zz=0;
    cout<<maxn<<endl;
    cout<<mx<<' '<<k<<endl;
    for(int i=0;i<v.size();i++)v[i].first=min(v[i].first,mx);
    int x=0;
    for(int i=0;i<mx;i++)
    {
        for(int j=0;j<k;j++,x++)
        {
            if(!v[zz].first)zz++;
            ans[getnum(x%mx,(x%mx+x/mx)%k)]=v[zz].second;
            //cout<<x%mx<<" "<<(x%mx+x/mx)%k<<endl;
            v[zz].first--;
        }
    }
    for(int i=0;i<mx;i++,cout<<endl)
        for(int j=0;j<k;j++)
    {
        cout<<ans[getnum(i,j)]<<' ';
    }
}
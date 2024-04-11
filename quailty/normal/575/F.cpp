//qscqesze
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 110
#define eps 1e-9
int Num;
//const int inf=0x7fffffff;   //&szlig;f3
const int inf=0x3f3f3f3f;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//**************************************************************************************

struct node
{
    ll x,y;
};
node a[5005];
vector<ll> Q;
ll dp[15050];
map<ll,int> H;
int main()
{
    int n=read();
    ll x=read();
    Q.push_back(x);
    for(int i=1;i<=n;i++)
    {
        a[i].x=read(),a[i].y=read();
        Q.push_back(a[i].x);
        Q.push_back(a[i].y);
    }
    sort(Q.begin(),Q.end());
    Q.erase(unique(Q.begin(),Q.end()),Q.end());
    for(int i=0;i<Q.size();i++)
        dp[i]=abs(Q[i]-x);
    for(int i=0;i<Q.size();i++)
        H[Q[i]]=i;
    for(int i=1;i<=n;i++)
    {
        ll tmp=dp[0]-Q[0];
        for(int j=1;j<Q.size();j++)
        {
            dp[j]=min(dp[j],tmp+Q[j]);
            tmp=min(tmp,dp[j]-Q[j]);
        }
        tmp=dp[Q.size()-1]+Q[Q.size()-1];
        for(int j=Q.size()-2;j>=0;j--)
        {
            dp[j]=min(dp[j],tmp-Q[j]);
            tmp=min(tmp,dp[j]+Q[j]);
        }
        for(int j=0;j<Q.size();j++)
        {
            if(Q[j]<a[i].x||Q[j]>a[i].y)dp[j]+=min(abs(Q[j]-a[i].y),abs(Q[j]-a[i].x));
        }
     /*   for(int j=0;j<Q.size();j++)
            cout<<dp[j]<<" ";
        cout<<endl;*/
    }
    ll ans = dp[0];
    for(int i=0;i<Q.size();i++)
        ans = min(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define F first
#define S second
#define pi acos(-1)
#define EPS 1e-9
#define MOD 1000000007
void IOS(){ios::sync_with_stdio(0);ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
int dx[9]= {1,-1,0,0,1,-1,1,-1,0};
int dy[9]= {0,0,1,-1,1,-1,-1,1,0};
const int N=200005;
#define pr pair<int,int>
priority_queue<pr> pq;
int n,t,a[N],i,j,s[N],c[N],l[N],r[N],v[N],ans,x,y;
int main()
{
    IOS();
    cin>>n;
	for(i=0;i<n;i++)
        cin>>a[i];
	for(i=j=0;i<n;i=j)
    {
		while(a[++j]==a[i]);
		s[++t]=a[i];
		c[t]=j-i;
		l[t]=t-1,r[t]=t+1;
		pq.push({c[t],-t});
	}
	while(pq.size())
	{
        t=-pq.top().second;
        pq.pop();
        if(v[t])continue;
        ans++;
        v[t]=1;
        x=l[t],y=r[t];
        l[y]=x,r[x]=y;
        if(l[t]&&s[x]==s[y]){
            c[x]+=c[y];
            v[y]=1;
            pq.push({c[x],-x});
            x=l[y];y=r[y];
            l[y]=x,r[x]=y;
        }
	}
	cout<<ans;
}
#include <bits/stdc++.h>
using namespace std;
int minn[1200005],a[300005],b[300005];
int num[300005];
vector<int>v[300005];
void change(int now,int l,int r,int ll,int rr,int num)
{
	if(ll<=l&&r<=rr)
	{
		minn[now]=num;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)
	    change(now<<1,l,mid,ll,rr,num);
	if(mid<rr)
	    change(now<<1|1,mid+1,r,ll,rr,num);
	minn[now]=min(minn[now<<1],minn[now<<1|1]);
}
int query(int now,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
		return minn[now];
	int ans=INT_MAX,mid=(l+r)>>1;
	if(mid>=ll)
	    ans=min(ans,query(now<<1,l,mid,ll,rr));
	if(mid<rr)
	    ans=min(ans,query(now<<1|1,mid+1,r,ll,rr));
	return ans;
}
void build(int now,int l,int r)
{
	if(l==r)
	{
		minn[now]=a[l];
		return;
	}
	int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    minn[now]=min(minn[now<<1],minn[now<<1|1]);
}
void cle(int now,int l,int r)
{
	minn[now]=INT_MAX;
	if(l==r)return;
	int mid=(l+r)>>1;
    cle(now<<1,l,mid);
    cle(now<<1|1,mid+1,r);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
        cin>>T;
	memset(minn,127,sizeof(minn));
	while(T--)
	{
		int n;
                cin>>n;
		cle(1,1,n);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			v[a[i]].push_back(i);
	    }
		build(1,1,n);
		for(int i=1;i<=n;i++)
		    cin>>b[i];
		int i;
	    for(i=1;i<=n;i++)
	    {
	    	num[b[i]]++;
	    	if(num[b[i]]>v[b[i]].size())
	    	{
	    		cout<<"NO";
	    		break;
			}
			if(query(1,1,n,1,v[b[i]][num[b[i]]-1])!=b[i])
			{
				cout<<"NO";
		        break;
			}
			change(1,1,n,v[b[i]][num[b[i]]-1],v[b[i]][num[b[i]]-1],INT_MAX);
	    }
	    if(i==n+1)
	        cout<<"YES";
	    for(i=1;i<=n;i++) v[i].clear(),num[i]=0;
	    cout<<"\n";
	}
}
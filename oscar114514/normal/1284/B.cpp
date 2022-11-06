#include<bits/stdc++.h>
using namespace std;
int n,x,last;
int l[233333],ok[233333],maxx[233333],minn[233333],a[233333];
int BIT[2333333],BIT2[2333333],lim=1000005;
inline void change(int pos)
{
	pos++;
	for(int x=pos;x<=lim;x+=x&-x)
		BIT[x]++;
}
inline int query(int pos)
{
	pos++;
	int ret=0;
	for(int x=pos;x;x-=x&-x)
		ret+=BIT[x];
	return ret;
}
inline void change2(int pos)
{
	pos++;
	for(int x=pos;x<=lim;x+=x&-x)
		BIT2[x]++;
}
inline int query2(int pos)
{
	pos++;
	int ret=0;
	for(int x=pos;x;x-=x&-x)
		ret+=BIT2[x];
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
		last=0x3f3f3f3f;
		for(int j=1;j<=l[i];j++)
		{
			cin>>x;
			if(j==1)maxx[i]=x;
			if(x>last)ok[i]=1;
			last=x;
		}
		minn[i]=x;
	}
	long long cnt=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(ok[i])
		{
			cnt++;
			ans+=i*2-1;
		}
		else
		{
			ans+=2*cnt;
			ans+=query(maxx[i]-1);
			ans+=query2(lim)-query2(minn[i]);
			if(maxx[i]>minn[i])ans++;
			change(minn[i]);
			change2(maxx[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
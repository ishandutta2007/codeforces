#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

/*#include<cstdio>
#include<iostream>
#include<algorithm>
#include<iostream>
using namespace std;

int n,x,a,b;

int main()
{
	cin>>n>>x;
	if(n==2&&x==0)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	cout<<"YES"<<endl;
	for(int i=1;i+4<=n;i+=4)
	{
		cout<<i+100001<<" "<<i+100002<<" "<<i+100003<<" "<<i+100004<<" ";
	}
	if(n%4==1)
		cout<<x;
	if(n%4==2)
		cout<<x+(1<<18)<<" "<<(1<<18);
	if(n%4==3)
		cout<<x+(1<<18)<<" "<<(1<<19)<<" "<<((1<<18)+(1<<19));
	if(n%4==0)
		cout<<x<<" "<<(1<<18)<<" "<<(1<<19)<<" "<<((1<<18)+(1<<19));
}*/

int n,p[2],cnt[2];

int calc(int l,int r,bool flag);

void dfs(int l,int r,int flag)
{
	if(p[0]&&p[1])
	{
		cout<<"! "<<p[0]<<" "<<p[1];
		fflush(stdout);
		exit(0);
	}
	if(l>r)
		return;
	int mid=l+r>>1;
	int x=calc(l,mid,flag);
	if(x==mid-l+1)
		p[flag]=l,dfs(mid+1,r,flag^1);
	else 
	if(!x)
		p[flag^1]=l,dfs(mid+1,r,flag);
	else 
		dfs(l,mid,flag);
}

int calc(int l,int r,bool flag)
{
	cout<<"? ";
	if(flag&1)
	{
		for(int i=1;i<l;i++)
			cout<<1;
		for(int i=l;i<=r;i++)
			cout<<0;
		for(int i=r+1;i<=n;i++)
			cout<<1;
	}
	else
	{
		for(int i=1;i<l;i++)
			cout<<0;
		for(int i=l;i<=r;i++)
			cout<<1;
		for(int i=r+1;i<=n;i++)
			cout<<0;
	}
	cout<<endl;
	fflush(stdout);
	int cc;
	cin>>cc;
	return (r-l+1+cc-cnt[flag])/2;
}

int main()
{
	cin>>n;
	int l=1,r=n;
	cout<<"? ";
	for(int i=1;i<=n;i++)
		cout<<0;
	cout<<endl;
	fflush(stdout);
	cin>>cnt[0];
	cnt[1]=n-cnt[0];
	dfs(1,n,0);
}
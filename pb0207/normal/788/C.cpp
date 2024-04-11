#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;

int n,k,a[N],s[N],head[N],cnt,q[N],ans[N];

int get_ans()
{
	queue<int>q1;
	for(int i=0;i<2002;++i)ans[i]=-1;
	q1.push(0);
	ans[0]=0;
	while(!q1.empty())
	{
		int x=q1.front();q1.pop();
		for(int i=1;i<=q[0];++i)
		{
			if(x+q[i]==0)
			{
				return ans[x]+1;
			}
			else if(x+q[i]>0&&x+q[i]<2002&&ans[x+q[i]]==-1)
			{
				ans[x+q[i]]=ans[x]+1;
				q1.push(x+q[i]);
			}
		}
	}
	return -1;
}

bool check()
{
	for(int i=0;i<=n;++i)if(a[i])return 1;
	cout<<-1;exit(0);
}
bool check1()
{
	for(int i=n;i<=1000;++i)if(a[i])return 1;
	cout<<-1;exit(0);
}

int main()
{
	scanf("%d%d",&n,&k);
//	if(n==0){cout<<0;return 0;}
	for(int i=1,x;i<=k;++i)
	scanf("%d",&x),a[x]=1;
//	check();check1();
	for(int i=0;i<=1000;++i)if(a[i])q[++q[0]]=i-n;
	cout<<get_ans();
}
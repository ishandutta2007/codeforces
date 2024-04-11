#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>fibbo[201];
/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N];

bool ok=false;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i!=0&&a[i]>1&&a[i-1]>1)
			ok=true;
	}
	if(!ok)
	{
		puts("perfect");
		return 0;
	}
	puts("ambiguous");
	printf("0 ");
	int now=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
			printf("%d ",now);
		now+=a[i-1];
	}
	puts(""); 
	printf("0 ");
	now=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<a[i];j++)
			printf("%d ",now);
		if(a[i-1]>=2&&a[i]>=2)
			printf("%d ",now+1);
		else
			printf("%d ",now);
		now+=a[i-1];
	}
}
*/
bool cab(int x,int y,int a=-1,int b=666) 
{
	bool flag=true;
	for(int i=fibbo[x].size()-3;i>=0;i--) 
		if(abs(fibbo[x][i+2]+y*fibbo[x-2][i])>1)
			flag=false;
	return flag;
}

int n;

void output(int x)
{
	for(int i=fibbo[x].size()-1;i>=0;i--)
		printf("%d ",fibbo[x][i]);
	puts("");
}

/*
#include<cstdio>
using namespace std;

int t[3],n;

int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),t[x]++;
	int ans=0;
	if(t[2]>=t[1])
		ans=t[1];
	else
	{
		ans=t[2];
		t[1]-=t[2];
		ans+=t[1]/3;
	}
	printf("%d",ans);
}
*/

int main() 
{
	scanf("%d",&n);
	fibbo[0].push_back(1);
	fibbo[1].push_back(1);
	fibbo[1].push_back(0);
	for(int i=2;i<=n;i++) 
	{
		fibbo[i]=fibbo[i-1];
		fibbo[i].push_back(0);
		int t1=1,t2=-1;
		bool flag=false;
		if(cab(i,t1)) 
		{
			for(int j=fibbo[i].size()-3;j>=0;j--)
				fibbo[i][j+2]+=fibbo[i-2][j];
		}
		else
		if(cab(i,t2)) 
		{
			for(int j=fibbo[i].size()-3;j>=0;j--)
				fibbo[i][j+2]-=fibbo[i-2][j];
		}
	}
	printf("%d\n",fibbo[n].size()-1);
	output(n);
	printf("%d\n",fibbo[n-1].size()-1);
	output(n-1);
}
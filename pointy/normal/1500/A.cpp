#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=200001;
int n,m,T; 
struct point
{
	int x,id;
}a[N];
bool cmp(point x,point y)
{
	return x.x<y.x;
}

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 
int d[5000006];
int u[2500006][2];
int q[5000006];
int main()
{
	n=read();
	for (int i=1;i<=n;i++) 
	{
		a[i].x=read();
		a[i].id=i;
		q[a[i].x]=i;
	}
	
	sort(a+1,a+n+1,cmp);
	memset(u,-1,sizeof(u));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			int v=a[i].x-a[j].x;
			if (u[v][0]!=-1&&u[v][0]<j) 
			{
				cout << "YES\n";
				cout << a[i].id << " " << a[u[v][1]].id << " " << a[j].id << " ";
				cout << a[u[v][0]].id;
				return 0;
			}
			if (u[v][0]==-1) u[v][0]=i,u[v][1]=j;
		}
	}
	cout << "NO";
	return 0;
}
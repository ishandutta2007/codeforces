/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

double x[4],y[4],b1,k1,b2,k2,dx,dy;

double d1,d2;

int main()
{
	cin>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3];
	d1=y[1]-y[2];
	d1/=(x[1]-x[2]);
	d2=y[2]-y[3];
	d2/=x[2]-x[3];
	k1=(x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]);
	k2=(x[2]-x[3])*(x[2]-x[3])+(y[2]-y[3])*(y[2]-y[3]);
	if(d1==d2||k1!=k2)
		cout<<"no";
	else
		cout<<"yes";
}
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const double pi=acos(-1);

const int N=1e3+1e2+7;

struct node{
	double a,b,c,d,e;
}s[N];

double a[N][N],b[N][N],c[N][N],d[N][N],e[N][N];

int n,calc[N],ans[N];

double dot(int i,int k,int j)
{
	return 	a[i][k]*a[i][j]+b[i][k]*b[i][j]+c[i][k]*c[i][j]+d[i][k]*d[i][j]+e[i][k]*e[i][j];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i].a>>s[i].b>>s[i].c>>s[i].d>>s[i].e;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			a[i][j]=s[j].a-s[i].a;
			b[i][j]=s[j].b-s[i].b;
			c[i][j]=s[j].c-s[i].c;
			d[i][j]=s[j].d-s[i].d;
			e[i][j]=s[j].e-s[i].e;
		}
	for(int i=1;i<=n;i++)
	{
		if(calc[i])
			continue;
		bool flag=true;
		for(int j=1;j<=n;j++)
			if(i!=j&&flag)
			{
				for(int k=1;k<j;k++)
					if(i!=k&&flag)
					{
						double tmp=acos(dot(i,j,k)/(sqrt(dot(i,k,k))*sqrt(dot(i,j,j))));
						if(tmp>=pi/2)
							calc[j]=1,calc[k]=1;
						else    
						{
							calc[i]=1,flag=false;
							break;
						}
					}
			}
	}
	for(int i=1;i<=n;i++)
		if(!calc[i])
			ans[++ans[0]]=i;
	for(int i=0;i<=ans[0];i++)
		cout<<ans[i]<<endl;
}
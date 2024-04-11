#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 510
using namespace std;
vector<int> vt[N];
int n,m,ba,bb,cnt=0;
double a[N][N],p[N];//af(x,y)
map<pair<int,int>,int> mp;//f(x,y)a
int rint(){
	int ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
double rdou(){
	double ret=0,uu=1,td=0.1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	while(c=='.') c=getchar();
	while(isdigit(c)) ret=ret+(c-'0')*td,td/=10,c=getchar();
	return ret*uu;
}
void gauss()
{
	int i,j,k,l;
	double beg;
	for(i=0;i<cnt;i++)
	{
		for(j=i;j<cnt;j++)
		{
			if(a[j][i]!=0)
			{
				break;
			}
		}
		//
		for(k=0;k<=cnt;k++)
		{
			swap(a[i][k],a[j][k]);
		}
		beg=a[i][i];
		for(k=0;k<=cnt;k++)
		{
			a[i][k]/=beg;
		}
		for(k=0;k<cnt;k++)
		{
			if(k==i)
			{
				continue;
			}
			beg=a[k][i];
			for(l=0;l<=cnt;l++)
			{
				a[k][l]-=beg*a[i][l];
			}
		}
	}
	for(i=cnt-1;i>=0;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			a[j][cnt]-=a[j][i]*a[i][cnt];
		}
	}
	return;
}
void init(int x)
{
	int i,j,k,l,t1,t2,nm;
	a[mp[make_pair(ba,bb)]][cnt]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			nm=mp[make_pair(i,j)];
			if(i!=j)
			{
				a[nm][nm]=1-p[i]*p[j];
			}
			else
			{
				a[nm][nm]=1;
			}
			for(k=0;k<vt[i].size();k++)
			{
				t1=vt[i][k];
				if(t1!=j)
				{
					a[nm][mp[make_pair(t1,j)]]-=p[j]*((double)1-p[t1])/(double)vt[t1].size();
				}
			}
			for(k=0;k<vt[j].size();k++)
			{
				t1=vt[j][k];
				if(t1!=i)
				{
					a[nm][mp[make_pair(i,t1)]]-=p[i]*((double)1-p[t1])/(double)vt[t1].size();
				}
			}
			for(k=0;k<vt[i].size();k++)
			{
				t1=vt[i][k];
				for(l=0;l<vt[j].size();l++)
				{
					t2=vt[j][l];
					if(t1==t2)
					{
						continue;
					}
					a[nm][mp[make_pair(t1,t2)]]-=((double)1-p[t1])/(double)vt[t1].size()*(1-p[t2])/(double)vt[t2].size();
				}
			}
		}
	}
	return;
}
int main(){
	double ans;
	int i,j,x,y;
	n=rint();
	m=rint();
	ba=rint();
	bb=rint();
	ba--;
	bb--;
	for(i=0;i<m;i++)
	{
		x=rint();
		y=rint();
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	for(i=0;i<n;i++)
	{
		p[i]=rdou();
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			mp[make_pair(i,j)]=cnt++;
		}
	}
	for(j=0;j<N;j++)
	{
		for(x=0;x<N;x++)
		{
			a[j][x]=0;
		}
	}
	init(i);//
	gauss();// 
	for(i=0;i<n;i++)
	{
		ans=a[mp[make_pair(i,i)]][cnt];
		printf("%.10f ",ans);
	}
	puts("");
	return 0;
}
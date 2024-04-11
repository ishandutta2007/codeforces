#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

#define maxn 130

struct mat
{
    int n,m;
    double a[maxn][maxn];
    mat(int n1,int m1)
    {
        n=n1;
        m=m1;
        memset(a,0,sizeof(a));
    }
    mat operator*(const mat &o)
    {
        mat c(n,o.m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<o.m;j++)
            {
                double tmp=0;
                for(int k=0;k<m;k++)
                    tmp=(tmp+a[i][k]*o.a[k][j]);
                c.a[i][j]=tmp;
            }
        }
        return c;
    }
};


mat pow(mat x,int y)
{
    if (y==1) return x;
    mat res=pow(x,y>>1);
    res=res*res;
    if (y&1) res=res*x;
    return res;
}

double p[maxn];
mat trans(128,128),st(128,1);
int n,k;

int main()
{
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i=0;i<=k;i++)
		scanf("%lf",&p[i]);
	
	for(int i=0;i<128;i++)
	{
		for(int j=0;j<128;j++)
		{
			trans.a[i][j]=p[i^j];
		}
	}
	/*
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			cerr<<trans.a[i][j]<<' ';
		cerr<<endl;
	}
	*/
	st.a[0][0]=1;
	trans=pow(trans,n);
	st=trans*st;
	double ans=0;
	for(int i=1;i<128;i++)
		ans+=st.a[i][0];
	printf("%.9lf\n",ans);
	return 0;
}
#include <cstdio>
using namespace std;

char A[1000000];
int x[1000000];
int y[1000000];
int N,M;

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%s",&A[M*i]);
	int ways = 1;
	for(int i=0;i<N*M;i++)
	{
		if(A[i]=='1'){x[i]=1;y[i]=1;}
		else if(A[i]=='2'){x[i]=1;y[i]=0;}
		else if(A[i]=='3'){x[i]=0;y[i]=0;}
		else if(A[i]=='4'){x[i]=0;y[i]=1;}
		else {x[i]=2;y[i]=2;}
	}
	int xset;
	for(int i=0;i<N;i++)
	{
		xset = 2;
		for(int j=0;j<M;j++)
		{
			if(xset!=2) xset = 1-xset;
			if(xset==2) xset = x[M*i+j];
			else if(x[M*i+j]==2) x[M*i+j] = xset;
			else if(xset != x[M*i+j]) ways = 0;
		}
		xset = 2;
		for(int j=M-1;j>=0;j--)
		{
			if(xset!=2) xset = 1-xset;
			if(xset==2) xset = x[M*i+j];
			else if(x[M*i+j]==2) x[M*i+j] = xset;
			else if(xset != x[M*i+j]) ways = 0;
		}
	}
	int yset;
	for(int j=0;j<M;j++)
	{
		yset = 2;
		for(int i=0;i<N;i++)
		{
			if(yset!=2) yset = 1-yset;
			if(yset==2) yset = y[M*i+j];
			else if(y[M*i+j]==2) y[M*i+j] = yset;
			else if(yset != y[M*i+j]) ways = 0;
		}
		yset = 2;
		for(int i=(N-1);i>=0;i--)
		{
			if(yset!=2) yset = 1-yset;
			if(yset==2) yset = y[M*i+j];
			else if(y[M*i+j]==2) y[M*i+j] = yset;
			else if(yset != y[M*i+j]) ways = 0;
		}
	}
	for(int i=0;i<N;i++)
		if(x[M*i]==2) ways = (2*ways)%1000003;
	for(int j=0;j<M;j++)
		if(y[j]==2) ways = (2*ways)%1000003;
	printf("%d\n",ways);
	return 0;
}
# include <cstdio>
# include <iostream>

using namespace std;

long long DP[200000][2];
int inp[200000];
int N;

long long getDP(int pos,int dir,bool flag)
{
	if(DP[pos][dir]!=0)return DP[pos][dir];
	DP[pos][dir]=-1;
	int nextpos;
	if(dir==0)nextpos=pos+inp[pos];
	else nextpos=pos-inp[pos];
	if(nextpos>=N||nextpos<0)
	{
		if(flag)DP[pos][dir]=inp[pos];
		else DP[pos][dir]=0;
		return inp[pos];
	}
	else if(DP[nextpos][1-dir]==-1)
	{
		if(flag)DP[pos][dir]=-1;
		else DP[pos][dir]=0;
		return -1;
	}
	else
	{
		long long ret=getDP(nextpos,1-dir,flag);
		if(ret<1)
		{
			if(flag)DP[pos][dir]=ret;
			else DP[pos][dir]=0;
			return ret;
		}
		else
		{
			if(flag)DP[pos][dir]=ret+inp[pos];
			else DP[pos][dir]=0;
			return ret+inp[pos];
		}
	}
}

int main()
{
	scanf("%d",&N);

	for(int i=1;i<N;i++)
		scanf("%d",inp+i);
	
	DP[0][0]=DP[0][1]=-2;
	for(int i=1;i<N;i++)
		getDP(i,0,true),getDP(i,1,true);
	for(int i=0;i<N;i++)
	{
		if(DP[i][0]==-2)DP[i][0]=0;
		if(DP[i][1]==-2)DP[i][1]=0;
	}

	for(int i=1;i<N;i++)
	{
		inp[0]=i;
		long long ret=getDP(0,0,false);
		if(ret==-1)printf("-1\n");
		else cout<<ret<<endl;
	}
	return 0;
}
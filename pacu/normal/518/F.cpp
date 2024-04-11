#include <iostream>
#include <cstdio>
using namespace std;

class fenwick
{
public:
	fenwick()
	{
		size = 2005;
		T = new int[size+1];
		for(int i=0;i<=size;i++)
			T[i] = 0;
	}
	~fenwick()
	{
		delete [] T;
		T = NULL;
	}
	long long getSum(int i)
	{
		long long c=0;
		for(++i; i > 0 ; i -= (i & -i))
		{
			c += T[i];
		}
		return c;
	}
	long long getRange(int i,int j)
	{
		return getSum(j)-getSum(i-1);
	}
	void set(int i,int dif)
	{
		for(++i; i < size ; i += (i & -i))
			T[i] += dif;
	}
private:
	int *T;
	int size;
};

char A[2002][2002];
int R,C;
fenwick fRowTop[2000];
fenwick fRowBot[2000];
fenwick fColLeft[2000];
fenwick fColRight[2000];
int blockLeft[2000][2000];
int blockRight[2000][2000];
int blockTop[2000][2000];
int blockBot[2000][2000];

int main()
{
	scanf("%d %d",&R,&C);
	for(int i=0;i<R;i++)
		scanf("%s",A[i]);
	for(int j=0;j<C;j++)
	{
		if(A[0][j]=='#') blockTop[0][j] = 0;
		else blockTop[0][j] = -1;
	}
	for(int i=1;i<R;i++)
		for(int j=0;j<C;j++)
		{
			if(A[i][j]=='#') blockTop[i][j] = i;
			else blockTop[i][j] = blockTop[i-1][j];
		}
	for(int j=0;j<C;j++)
	{
		if(A[R-1][j]=='#') blockBot[R-1][j] = R-1;
		else blockBot[R-1][j] = R;
	}
	for(int i=(R-2);i>=0;i--)
		for(int j=0;j<C;j++)
		{
			if(A[i][j]=='#') blockBot[i][j] = i;
			else blockBot[i][j] = blockBot[i+1][j];
		}
	for(int i=0;i<R;i++)
	{
		if(A[i][0]=='#') blockLeft[i][0] = 0;
		else blockLeft[i][0] = -1;
	}
	for(int j=1;j<C;j++)
		for(int i=0;i<R;i++)
		{
			if(A[i][j]=='#') blockLeft[i][j] = j;
			else blockLeft[i][j] = blockLeft[i][j-1];
		}
	for(int i=0;i<R;i++)
	{
		if(A[i][C-1]=='#') blockRight[i][C-1] = C-1;
		else blockRight[i][C-1] = C;
	}
	for(int j=(C-2);j>=0;j--)
		for(int i=0;i<R;i++)
		{
			if(A[i][j]=='#') blockRight[i][j] = j;
			else blockRight[i][j] = blockRight[i][j+1];
		}

	///////////////////////////////////////////
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(blockTop[i][j]==-1) fRowTop[i].set(j,1);
			if(blockBot[i][j]==R) fRowBot[i].set(j,1);
			if(blockLeft[i][j]==-1) fColLeft[j].set(i,1);
			if(blockRight[i][j]==C) fColRight[j].set(i,1);
		}
	}
	////////////////////////////////////////////
	long long total = 0;

	//top to bottom
	for(int i=1;i<(R-1);i++)
	{
		for(int j=1;j<(C-1);j++)
		{
			if(blockTop[i][j]!=-1) continue;
			int lft = blockLeft[i][j]+1;
			int rht = blockRight[i][j]-1;
			if(lft==0) lft++;
			if(rht==(C-1)) rht--;
			total += fRowBot[i].getRange(lft,rht);
			if(blockBot[i][j]==R) total--;
		}
	}
	//left to right
	for(int i=1;i<(R-1);i++)
	{
		for(int j=1;j<(C-1);j++)
		{
			if(blockLeft[i][j]!=-1) continue;
			int tp = blockTop[i][j]+1;
			int bt = blockBot[i][j]-1;
			if(tp==0) tp++;
			if(bt==(R-1)) bt--;
			total += fColRight[j].getRange(tp,bt);
			if(blockRight[i][j]==C) total--;
		}
	}
	//left to up, left to down, right to up, right to down
	for(int i=1;i<(R-1);i++)
	{
		for(int j=1;j<(C-1);j++)
		{
			if(blockLeft[i][j]==-1)
			{
				if(blockTop[i][j]==-1) total++;
				if(blockBot[i][j]==R) total++;
			}
			if(blockRight[i][j]==C)
			{
				if(blockTop[i][j]==-1) total++;
				if(blockBot[i][j]==R) total++;
			}
		}
	}
	//top to top
	for(int i=1;i<(R-1);i++)
	{
		for(int j=1;j<(C-1);j++)
		{
			if(blockTop[i][j]!=-1) continue;
			int lft = j+2;
			int rht = blockRight[i][j]-1;
			if(rht==(C-1)) rht--;
			if(rht < lft) continue;
			total += fRowTop[i].getRange(lft,rht);
		}
	}
	//bottom to bottom
	for(int i=1;i<(R-1);i++)
	{
		for(int j=1;j<(C-1);j++)
		{
			if(blockBot[i][j]!=R) continue;
			int lft = j+2;
			int rht = blockRight[i][j]-1;
			if(rht==(C-1)) rht--;
			if(rht < lft) continue;
			total += fRowBot[i].getRange(lft,rht);
		}
	}
	//left to left
	for(int i=1;i<(R-1);i++)
	{
		for(int j=1;j<(C-1);j++)
		{
			if(blockLeft[i][j]!=-1) continue;
			int tp = i+2;
			int bt = blockBot[i][j]-1;
			if(bt==(R-1)) bt--;
			if(bt < tp) continue;
			total += fColLeft[j].getRange(tp,bt);
		}
	}
	//right to right
	for(int i=1;i<(R-1);i++)
	{
		for(int j=1;j<(C-1);j++)
		{
			if(blockRight[i][j]!=C) continue;
			int tp = i+2;
			int bt = blockBot[i][j]-1;
			if(bt==(R-1)) bt--;
			if(bt < tp) continue;
			total += fColRight[j].getRange(tp,bt);
		}
	}
	//no turns at all
	for(int i=1;i<(R-1);i++)
		if((blockLeft[i][0]==-1)&&(blockRight[i][0]==C))
			total++;
	for(int j=1;j<(C-1);j++)
		if((blockTop[0][j]==-1)&&(blockBot[0][j]==R))
			total++;


	cout << total << endl;
	return 0;
}
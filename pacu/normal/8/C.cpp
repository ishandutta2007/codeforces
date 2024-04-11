#include <iostream>
#include <vector>
using namespace std;
#define BITMAX (1<<24)
#define INFINITY (1<<29)

struct obj
{
	int x,y;
};

int tm(obj a,obj b)
{
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int dp[BITMAX];
int last1[BITMAX];
int last2[BITMAX];

int main()
{
	int N;
	obj bag;
	vector<obj> A;
	int i,j;
	int o1,o2;
	for(i=0;i<BITMAX;i++)
		dp[i] = INFINITY;
	cin >> bag.x >> bag.y >> N;
	for(i=0;i<N;i++)
	{
		A.push_back(obj());
		cin >> A[i].x >> A[i].y;
	}
	dp[0] = 0;
	for(i=0;i<(1<<N);i++)
	{
		for(o1=(N-1);o1>=0;o1--)
		{
			if(i&(1<<o1)) break;
			j = i|(1<<o1);
			if(dp[j]>(dp[i]+2*tm(bag,A[o1])))
			{
				dp[j] = dp[i]+2*tm(bag,A[o1]);
				last1[j] = o1;
				last2[j] = -1;
			}
			for(o2=0;o2<o1;o2++)
			{
				if(i&(1<<o2)) continue;
				if(dp[j|(1<<o2)]>(dp[i]+tm(bag,A[o1])+tm(bag,A[o2])+tm(A[o1],A[o2])))
				{
					dp[j|(1<<o2)] = dp[i]+tm(bag,A[o1])+tm(bag,A[o2])+tm(A[o1],A[o2]);
					last1[j|(1<<o2)] = o1;
					last2[j|(1<<o2)] = o2;
				}
			}
		}
	}
	int newj,newj2;
	/*
	else
	{
		int mn = INFINITY;
		int mnj = -1;
		int mnobj = -1;
		for(o1=0;o1<N;o1++)
		{
			j = (~(1<<o1)) & ((1<<N)-1);
			if((dp[j]+2*tm(bag,A[o1]))<mn)
			{
				mn = dp[j]+2*tm(bag,A[o1]);
				mnj = j;
				mnobj = o1;
			}
		}
		j = mnj;
		cout << mn << endl;
		cout << 0 << " " << mnobj+1 << " ";
	}*/
	cout << dp[(1<<N)-1] << endl;
	for(j=((1<<N)-1);j>0;)
	{
		cout << 0 << " " << last1[j]+1 << " ";
		if(last2[j]>-1)
			cout << last2[j]+1 << " ";
		newj = j & ((~(1<<last1[j]))&((1<<N)-1));
		if(last2[j]>-1)
			newj2 = newj & ((~(1<<last2[j]))&((1<<N)-1));
		else
			newj2 = newj;
		j = newj2;
	}
	cout << 0 << endl;
}
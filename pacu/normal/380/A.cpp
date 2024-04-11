#include <iostream>
#include <vector>
using namespace std;

struct stage
{
	int tp;
	long long x,l,c;
	long long len;
};

stage A[100000];
vector<long long> first;

long long binSearch(long long low,long long high,long long val)
{
	if(low==high) return low;
	if((low+1)==high)
	{
		if(A[low].len >= val) return low;
		return high;
	}
	long long mid = (low+high)/2;
	if(A[mid].len >= val)
		return binSearch(low,mid,val);
	else
		return binSearch(mid+1,high,val);
}

int main()
{
	int N;
	cin >> N;
	long long length = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i].tp;
		if(A[i].tp==1)
		{
			cin >> A[i].x;
			if(first.size() < 10e5)
				first.push_back(A[i].x);
			length++;
		}
		else
		{
			cin >> A[i].l >> A[i].c;
			if(first.size() < 10e5)
			{
				for(int k=0;k<A[i].c;k++)
				{
					if(first.size() == 10e5)
						break;
					for(int j=0;j<A[i].l;j++)
					{
						if(first.size() == 10e5)
							break;
						first.push_back(first[j]);
					}
				}
			}
			length += ((long long)A[i].l)*((long long)A[i].c);
		}
		A[i].len = length;
	}
	int Q;
	cin >> Q;
	for(int i=0;i<Q;i++)
	{
		long long v;
		cin >> v;
		long long iStage = binSearch(0,N-1,v);
		if(A[iStage].tp == 1)
			cout << A[iStage].x << " ";
		else
		{
			v -= A[iStage-1].len;
			v = ((v-1)%A[iStage].l);
			cout << first[v] << " ";
		}
	}
}
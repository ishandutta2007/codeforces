#include <iostream>
#include <algorithm>
using namespace std;

int A[100000];
bool loc[100000];
int index[100000];

int id[100000];
int sz[100000];
int canBe[100000];	//canBe = 11,01,10,00 first digit A, second digit B

int find(int i)
{
	int j = i;
	while(j != id[j])
		j = id[j];
	id[i] = j;
	return j;
}

void join(int i,int j)
{
	int ri = find(i);
	int rj = find(j);
	if(ri==rj) return;
	if(sz[ri] <= sz[rj])
	{
		id[ri] = rj;
		sz[rj] += ri;
		canBe[rj] = canBe[rj] & canBe[ri];
	}
	else
		join(j,i);
}

int binSearch(int low,int high,int x)
{
	if(low==high) return low;
	if(low==(high-1))
	{
		if(A[index[low]]==x) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(A[index[mid]] < x)	return binSearch(mid+1,high,x);
	else					return binSearch(low,mid,x);
}

bool cmp(int a,int b)
{
	return A[a]<A[b];
}
bool cmp2(int a,int b)
{
	return a<b;
}

int main()
{
	int N,a,b;
	cin >> N >> a >> b;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		loc[i] = 0;
		index[i] = i;
	}
	sort(index,index+N,cmp);
	for(int i=0;i<N;i++)
	{
		int iA = binSearch(0,N-1,a-A[index[i]]);
		int iB = binSearch(0,N-1,b-A[index[i]]);
		bool foundA = (A[index[iA]]==(a-A[index[i]]));
		bool foundB = (A[index[iB]]==(b-A[index[i]]));
		canBe[index[i]] = 2*foundA + foundB;
		sz[index[i]] = 1;
		id[index[i]] = index[i];
	}
	for(int i=0;i<N;i++)
	{
		int iA = binSearch(0,N-1,a-A[index[i]]);
		int iB = binSearch(0,N-1,b-A[index[i]]);
		bool foundA = (A[index[iA]]==(a-A[index[i]]));
		bool foundB = (A[index[iB]]==(b-A[index[i]]));
		if(foundA)
			join(index[i],index[iA]);
		if(foundB)
			join(index[i],index[iB]);
	}
	for(int i=0;i<N;i++)
		if(canBe[i]==0)
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	for(int i=0;i<N;i++)
	{
		if(canBe[find(i)] & 2)
			cout << "0 ";
		else
			cout << "1 ";
	}
}
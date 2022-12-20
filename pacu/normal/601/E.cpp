#include <iostream>
#include <cassert>
using namespace std;

int N,K,Q;

int itemValue[15000];
int itemMass[15000];
int itemBegin[15000];
int itemEnd[15000];
int cnt[15000];

int queryTime[32768];
int s[32768][1001];
int numAdded[32768];
int numNeeded[32768];

int etp[100000];
int ei[100000];

void add(int query,int item)
{
	for(int c=K;c>=itemMass[item];c--)
		s[query][c] = max(s[query][c],s[query][c-itemMass[item]]+itemValue[item]);
}
void copy(int query1,int query2)
{
	for(int c=K;c>=0;c--)
		s[query1][c] = s[query2][c];
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	int T = 0;
	int numItems = 0;
	int numQueries = 0;
	for(;T<N;T++)
	{
		cin >> itemValue[numItems] >> itemMass[numItems];
		itemBegin[numItems] = T, itemEnd[numItems] = 100000;
		etp[T] = 0;
		ei[T] = numItems;
		numItems++;
	}
	cin >> Q;
	int tp,x;
	int curItems = N;
	for(;T<N+Q;T++)
	{
		cin >> tp;
		if(tp == 1)
		{
			cin >> itemValue[numItems] >> itemMass[numItems];
			itemBegin[numItems] = T, itemEnd[numItems] = 100000;
			etp[T] = 0;
			ei[T] = numItems;
			numItems++;
			curItems++;
		}
		else if(tp == 2)
		{
			cin >> x;
			itemEnd[x-1] = T;
			etp[T] = 0;
			ei[T] = x-1;
			curItems--;
		}
		else
		{
			queryTime[numQueries] = T;
			etp[T] = 1;
			ei[T] = numQueries;
			numNeeded[numQueries] = curItems;
			numQueries++;
		}
	}
	int onum = numQueries;
	while(numQueries != (numQueries & -numQueries))
	{
		etp[T] = 1;
		ei[T] = numQueries;
		queryTime[numQueries] = T;
		numNeeded[numQueries] = curItems;
		numQueries++,T++;
	}
	assert(T<100000);
	assert(numQueries<=32768);
	assert(numItems<=15000);
	for(int i=0;i<queryTime[0];i++)
	{
//		cout << '(' << etp[i] << ", " << ei[i] << ')' << '\n';
		if(itemEnd[ei[i]] > queryTime[numQueries-1])
		{
//				cout << "Added Item " << ei[i] << " to Query 0 through " << numQueries-1 << '\n';
			add(0,ei[i]);
			numAdded[0]++;
		}
	}
	for(int d=numQueries/2;d>=1;d/=2)
	{
		for(int i=0;i<numItems;i++)
			cnt[i] = 0;
		int left = 0;
		for(int i=numQueries-d;i>=0;i-=d,left^=1)
		{
			if(left)
			{
				for(int j=queryTime[i+d-1]+1;j<queryTime[i+2*d-1];j++)
					if(etp[j]==0)
					{
						if(itemBegin[ei[j]] < queryTime[i])
						{
//							cout << "Added Item " << ei[j] << " to Query" << i << " through " << i+d-1 << '\n';
							add(i,ei[j]);
							cnt[ei[j]]++;
							numAdded[i]++;
//							assert(cnt[ei[j]]<=2);
//							assert(itemEnd[ei[j]] > queryTime[i+d-1]);
//							assert(itemEnd[ei[j]] < queryTime[i+2*d-1]);
						}
					}
			}
			else
			{
				copy(i,i-d);
				numAdded[i] = numAdded[i-d];
//				cout << "range " << max(0,queryTime[i-1]+1) << " - " << queryTime[i]-1 << '\n';
				for(int j=queryTime[i-d]+1;j<queryTime[i];j++)
					if(etp[j]==0)
					{
						if(itemEnd[ei[j]] > queryTime[i+d-1])
						{
//							cout << "Added Item " << ei[j] << " to Query" << i << " through " << i+d-1 << '\n';
							add(i,ei[j]);
							cnt[ei[j]]++;
							numAdded[i]++;
//							assert(cnt[ei[j]]<=2);
//							assert(itemBegin[ei[j]] < queryTime[i]);
//							assert(itemBegin[ei[j]] > queryTime[i-d]);
						}
					}
			}
		}
	}
//	for(int i=0;i<numQueries;i++)
//		if(numAdded[i]!=numNeeded[i])
//			cout << numAdded[i] << ':' << numNeeded[i] << '\n';
	for(int i=0;i<T;i++)
	{
		if(etp[i]==1 && ei[i] < onum)
		{
			long long ans = 0;
			for(int c=K;c>=1;c--)
				ans = (ans*10000019+s[ei[i]][c])%1000000007;
			cout << ans << '\n';
		}
	}		
}
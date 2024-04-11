#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200000

int N,w;
int x[100000];
int v[100000];

int T[MAXN];

void update(int i,int c)
{
	for(i++;i<MAXN;i+=(i&-i))
		T[i] += c;
}

long long getSum(int i)
{
	long long c=  0;
	for(i++;i>0;i-=(i&-i))
		c += T[i];
	return c;
}

int cid[100000];
int posNeg[100000];
int back[100000];

bool cmpNeg(int a,int b)
{
	return abs(x[a])*((long long)abs(v[b] - w)) < abs(x[b])*((long long)abs(v[a] - w));
}

bool cmpPos(int a,int b)
{
	return abs(x[a])*((long long)abs(v[b] + w)) < abs(x[b])*((long long)abs(v[a] + w));
}

int main()
{
	cin >> N >> w;
	for(int i=0;i<N;i++)
	{
		cin >> x[i] >> v[i];
		cid[i] = i;
	}
	sort(cid,cid+N,cmpNeg);
	posNeg[cid[0]] = 0;
	for(int i=1;i<N;i++)
		posNeg[cid[i]] = posNeg[cid[i-1]] + cmpNeg(cid[i-1], cid[i]);
	sort(cid,cid+N,cmpPos);
	back[0] = -1;
	for(int i=1;i<N;i++)
	{
		if(cmpPos(cid[i-1], cid[i]))
			back[i] = i-1;
		else
			back[i] = back[i-1];
	}
	int j = 0;
	long long ans = (N*((long long)(N-1)))/2;
	for(int i=0;i<N;i++)
	{
		while(j <= back[i])
		{
			update(posNeg[cid[j]], 1);
			j++;
		}
		ans -= getSum(posNeg[cid[i]]-1);
	}
	cout << ans << '\n';
}
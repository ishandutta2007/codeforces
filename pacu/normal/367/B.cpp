#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MOD1 1500450271
#define MOD2 1000000009
#define B 1000000007

long long A[400000];
long long other[200000];
long long pw1[500000];
long long pw2[500000];

void computePowers()
{
	pw1[0] = 1;
	for(int i=1;i<500000;i++)
		pw1[i] = (pw1[i-1]*B)%MOD1;
	pw2[0] = 1;
	for(int i=1;i<500000;i++)
		pw2[i] = (pw2[i-1]*B)%MOD2;
}

long long nxt1(long long hash,long long ri,long long i)
{
	hash = (hash + pw1[A[i]])%MOD1;
	if(ri>=0LL)
		hash = (hash - pw1[A[ri]])%MOD1;
	if(hash<0LL) hash += MOD1;
	return hash;
}
long long nxt2(long long hash,long long ri,long long i)
{
	hash = (hash + pw2[A[i]])%MOD2;
	if(ri>=0LL)
		hash = (hash - pw2[A[ri]])%MOD2;
	if(hash<0LL) hash += MOD2;
	return hash;
}

long long hash1[200000];
long long hash2[200000];
int cid[400000];

bool cmp(int a,int b)
{
	return A[a]<A[b];
}

int main()
{
	computePowers();
	long long N,M,P;
	cin >> N >> M >> P;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int j=0;j<M;j++)
	{
		cin >> other[j];
		A[j+N] = other[j];
	}
	for(int i=0;i<N+M;i++)
		cid[i] = i;
	sort(cid,cid+N+M,cmp);
	int cnt = -1;
	int prv = -1;
	for(int i=0;i<N+M;i++)
	{
		if(A[cid[i]] != prv)
			cnt++;
		prv = A[cid[i]];
		A[cid[i]] = cnt;
	}

	long long o1 = 0;
	long long o2 = 0;
	for(int i=0;i<M;i++)
	{
		o1 = nxt1(o1,-1,N+i);
		o2 = nxt2(o2,-1,N+i);
	}
	vector<long long> ans;
	for(long long i=0;i<N;i++)
	{
		hash1[i%P] = nxt1(hash1[i%P],i-M*P,i);
		hash2[i%P] = nxt2(hash2[i%P],i-M*P,i);
		if((hash1[i%P]==o1)&&(hash2[i%P]==o2))
			ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i]-(M-1)*P+1 << " ";
	cout << "\n";
	return 0;
}
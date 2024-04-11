#include <iostream>
#include <algorithm>
using namespace std;

long long N,mx,cf,cm;
long long M;

long long A[100000];
int cid[100000];
long long B[100000];
long long ps[100000];

bool cmp(int a,int b)
{
	return A[a]<A[b];
}

long long binSearch(long long low,long long high,long long cur,int tp)
{
	if(low==high) return low;
	if(low+1==high)
	{
		int l = min(lower_bound(B,B+N,high)-B-1,tp);
		if(l<0 || ((l+1)*high-ps[l])<=cur) return high;
		return low;
	}
	long long mid = (low+high)/2;
	int l = min(lower_bound(B,B+N,mid)-B-1,tp);
	if(l<0 || ((l+1)*mid-ps[l])<=cur) return binSearch(mid,high,cur,tp);
	else return binSearch(low,mid-1,cur,tp);
}

long long mLev;

long long force(long long nPer)
{
	long long cur = M;
	long long ans = 0;
	long long topsm = ps[N-1];
	if(nPer<N) topsm -= ps[N-nPer-1];
	cur -= (nPer*mx-topsm);
	if(cur<0) return 0;
	mLev = mx;
	if(nPer==N) return cf*N+cm*mLev;
	mLev = binSearch(0,mx-1,cur,N-nPer-1);
	ans = cf*nPer+cm*mLev;
	return ans;
}


int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> mx >> cf >> cm >> M;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		cid[i] = i;
	}
	sort(cid,cid+N,cmp);
	for(int i=0;i<N;i++)
		B[i] = A[cid[i]];
	ps[0] = A[cid[0]];
	for(int i=1;i<N;i++)
		ps[i] = ps[i-1]+((long long)A[cid[i]]);
	long long best = 0;
	long long bestans = force(0);
	long long cans;
	for(int i=1;i<=N;i++)
	{
		cans = force(i);
		if(cans>bestans)
			bestans = cans, best = i;
	}
	cout << bestans << '\n';
	force(best);
	long long sm = 0;
	for(int i=0;i<N;i++)
	{
		long long old = A[cid[i]];
		if(A[cid[i]]<mLev) A[cid[i]] = mLev;
		if(i>=N-best) A[cid[i]] = mx;
		sm += A[cid[i]]-old;
	}
	for(int i=0;i<N;i++)
		cout << A[i] << ' ';
	cout << '\n';
	
}
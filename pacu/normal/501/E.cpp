#include <iostream>
using namespace std;

int totcnt[100000];
int cnt[100000];

int main()
{
	int N;
	int A[100000];
	cin >> N;
	for(int i=0;i<N;i++)
		totcnt[i] = cnt[i] = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		A[i]--;
		totcnt[A[i]]++;
	}
	int nOdd = 0;
	for(int i=0;i<N;i++)
		if(totcnt[i]%2)
			nOdd++;
	if(nOdd > N%2)
	{
		cout << 0 << endl;
		return 0;
	}
	int lGood = 0;
	for(;lGood < N/2;lGood++)
		if(A[lGood] != A[N-1-lGood])
			break;
	if(lGood == N/2)
	{
		long long ans = N;
		ans *= ((long long)(N+1));
		ans /= 2;
		cout << ans << endl;
		return 0;
	}
	int midGood = (N/2)-1;
	for(;midGood >= 0;midGood--)
		if(A[midGood] != A[N-1-midGood])
			break;

	int i = lGood;
	cnt[A[i]]++;
	cnt[A[N-1-i]]--;
	int cNeg = 0;
	if(cnt[A[N-1-i]]<0)
		cNeg++;
	int attain = midGood+1;
	if(N%2)
		if(!(totcnt[A[N/2]]%2))
			if((i-1)<(N/2))
				attain = N/2 + 1;
	for(i++;i<N/2;i++)
	{
		if(cNeg == 0)
			if(i>=attain)
				break;
		cnt[A[i]]++;
		cnt[A[N-1-i]]--;
		if(A[i] != A[N-1-i])
		{
			if(cnt[A[i]]==0)
				cNeg--;
			if(cnt[A[N-1-i]]==-1)
				cNeg++;
		}
	}
	if(cNeg > 0)
	{
		for(i=N/2;i<=N;i++)
		{
			if(cNeg == 0)
				break;
			if(2*i+1 == N)
			{
				cnt[A[i]]+=1;
				if((cnt[A[i]]<1)&&(cnt[A[i]]>=0))
					cNeg--;
			}
			else
			{
				cnt[A[i]]+=2;
				if((cnt[A[i]]<2)&&(cnt[A[i]]>=0))
					cNeg--;
			}
		}
	}
	long long ans = 0;
	ans += ((long long)(lGood+1))*((long long)(N+1-i));

	for(int j=0;j<N;j++)
		cnt[j] = 0;
	i = N-1-lGood;
	cnt[A[i]]++;
	cnt[A[N-1-i]]--;
	cNeg = 0;
	if(cnt[A[N-1-i]]<0)
		cNeg++;
	attain = N-2-midGood;
	if(N%2)
		if(!(totcnt[A[N/2]]%2))
			if((i+1)<(N/2))
				attain = N/2 - 1;
	for(i--;i>N/2;i--)
	{
		if(cNeg == 0)
			if(i <= attain)
				break;
		cnt[A[i]]++;
		cnt[A[N-1-i]]--;
		if(A[i] != A[N-1-i])
		{
			if(cnt[A[i]]==0)
				cNeg--;
			if(cnt[A[N-1-i]]==-1)
				cNeg++;
		}
	}
	if(cNeg > 0)
	{
		for(i=N/2;i>=-1;i--)
		{
			if(cNeg == 0)
				break;
			if(2*i+1 == N)
			{
				cnt[A[i]]+=1;
				if((cnt[A[i]]<1)&&(cnt[A[i]]>=0))
					cNeg--;
			}
			else
			{
				cnt[A[i]]+=2;
				if((cnt[A[i]]<2)&&(cnt[A[i]]>=0))
					cNeg--;
			}
		}
	}
	ans += ((long long)(lGood+1))*((long long)i+2);

	ans -= ((long long)(lGood+1))*((long long)(lGood+1));

	cout << ans << endl;
	return 0;
}
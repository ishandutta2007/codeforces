#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<long long,vector<long long> > mA,mB;
long long fact[20];
long long A[13];
long long B[13];
long long sA,sB;
long long N,K;
long long S;

void dfsA(long long i,long long cs,long long k)
{
	if(i==sA)
	{
		mA[cs].push_back(k);
		return;
	}
	dfsA(i+1,cs+0,k+0);
	if((cs+A[i])<=S)
		dfsA(i+1,cs+A[i],k+0);
	if((A[i]<=18)&&((cs+fact[A[i]])<=S)&&(k<K))
		dfsA(i+1,cs+fact[A[i]],k+1);
}

void dfsB(long long i,long long cs,long long k)
{
	if(i==sB)
	{
		mB[cs].push_back(k);
		return;
	}
	dfsB(i+1,cs+0,k+0);
	if((cs+B[i])<=S)
		dfsB(i+1,cs+B[i],k+0);
	if((B[i]<=18)&&((cs+fact[B[i]])<=S)&&(k<K))
		dfsB(i+1,cs+fact[B[i]],k+1);
}

int main()
{
	cin >> N >> K >> S;
	sA = sB = 0;
	for(long long i=0;i<N;i++)
	{
		if(i%2) cin >> A[sA++];
		else cin >> B[sB++];
	}
	fact[1] = 1;
	for(long long i=2;i<=18;i++)
		fact[i] = ((long long)i)*fact[i-1];
	if(N==1)
	{
		long long cnt = 0;
		if(B[0]==S) cnt++;
		if((B[0]<=18)&&(fact[B[0]]==S)) cnt+=K;
		cout << cnt << "\n";
		return 0;
	}
	dfsA(0,0,0);
	dfsB(0,0,0);
	unordered_map<long long,vector<long long> >::iterator it,it2;
	for(it=mA.begin();it!=mA.end();it++)
	{
		sort(it->second.begin(),it->second.end());
	}
	for(it=mB.begin();it!=mB.end();it++)
	{
		sort(it->second.begin(),it->second.end(),greater<long long>());
	}
	long long a,b;
	long long cura,curb;
	long long ka[14],kb[14];
	long long za,zb;
	long long total = 0;
	for(it=mA.begin();it!=mA.end();it++)
	{
		a = it->first;
		b = S-a;
		if(!mB.count(b)) continue;
		for(long long i=0;i<14;i++)
			ka[i] = kb[i] = 0;
		it2 = mB.find(b);
		cura = 0;
		curb = 0;
		za = it->second.size();
		zb = it2->second.size();
		long long ways = 0;
		for(;cura<za;cura++)
			ka[it->second[cura]]++;
		for(;curb<zb;curb++)
		{
			kb[it2->second[curb]]++;
			ways++;
		}
		for(cura=0,curb=0;cura<14;cura++)
		{
			if((K+1-cura)<14)
				ways -= kb[K+1-cura];
			total += ka[cura]*ways;
		}
	}
	cout << total << "\n";
	return 0;
}
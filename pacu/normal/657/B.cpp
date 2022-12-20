#include <iostream>
using namespace std;

int pos[300000],neg[300000];

void add(int k,int *a)
{
	int carry = 0;
	for(int i=0;i<32;i++)
	{
		a[i] += carry + (k%2);
		carry = a[i]/2;
		a[i] = a[i]%2;
		k = k/2;
	}
}

void sub(int *a,int *b)	//a - b
{
	int rem = 0;
	for(int i=0;i<250000;i++)
	{
		a[i] = a[i] - b[i] - rem;
		if(a[i] < 0)
		{
			if(a[i]%2 == -1)
			{
				rem = 1-(a[i]/2);
				a[i] = 1;
			}
			else
			{
				rem = -(a[i]/2);
				a[i] = 0;
			}
		}
		else
			rem = 0;
	}
}

int A[300001];

int main()
{
	int N,K;
	cin >> N >> K;
	N++;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		if(A[i]>0) add(A[i],pos+i);
		else if(A[i]<0) add(-A[i],neg+i);
	}
	bool und = 0;
	for(int i=250000;i>=0;i--)
	{
		if(pos[i]<neg[i]) und = 1;
		if(pos[i]!=neg[i]) break;
	}
	int ans = 0;
	if(!und)
	{
		sub(pos,neg);
		int hb = 0;
		for(int i=0;i<250000;i++)
			if(pos[i])
				hb = i;
		int lb = 0;
		for(int i=250000;i>=0;i--)
			if(pos[i])
				lb = i;
		for(int i=0;i<=lb && i<N;i++)
		{
			if(hb-i > 35) continue;
			long long c = 0;
			for(int j=hb;j>=i;j--)
			{
				c *= 2;
				c += pos[j];
			}
			if(-K <= A[i]-c && A[i]-c <= K)
				ans++;
			if(i==N-1 && A[i]==c)
				ans--;
		}
	}
	else
	{
		sub(neg,pos);
		int hb = 0;
		for(int i=0;i<250000;i++)
			if(neg[i])
				hb = i;
		int lb = 0;
		for(int i=250000;i>=0;i--)
			if(neg[i])
				lb = i;
		for(int i=0;i<=lb && i<N;i++)
		{
			if(hb-i > 35) continue;
			long long c = 0;
			for(int j=hb;j>=i;j--)
			{
				c *= 2;
				c += neg[j];
			}
			if(-K <= A[i]+c && A[i]+c <= K)
				ans++;
			if(i==N-1 && A[i]==-c)
				ans--;
		}
	}
	cout << ans << '\n';
}
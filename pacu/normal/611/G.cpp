#include <iostream>
using namespace std;
#define MOD 1000000007

long long aa(long long a)
{
	if(a<0) return -a;
	return a;
}

long long x[500000],y[500000];
long long sumx[500000],sumy[500000];
int N;

long long tot;
long long s[500000];
long long sums[500000];

long long tri(int i,int j)
{
	return aa(((long long)x[i])*((long long)y[j]) - ((long long)x[j])*((long long)y[i]));
}

long long gentri(int i,int j,int k)
{
	return aa(((long long)(x[i]-x[k]))*((long long)(y[j]-y[k])) - ((long long)(x[j]-x[k]))*((long long)(y[i]-y[k])));
}

long long poly(int i,int k)
{
	if(k<i) return ((tot-s[i])+s[k]+tri(i,k)+MOD)%MOD;
	else return (s[k]-s[i]-tri(i,k)+MOD+MOD)%MOD;
}

long long getsum(int start,int end,long long *ar)
{
	if(start > end) return 0;
	if(start==0) return ar[end];
	return (ar[end]+MOD-ar[start-1])%MOD;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> x[0] >> y[0];
	for(int i=1;i<N;i++)
	{
		cin >> x[i] >> y[i];
		x[i] -= x[0], y[i] -= y[0];
	}
	x[0] = 0, y[0] = 0;
	for(int i=1;i<N;i++)
	{
		s[i] = s[i-1]+tri(i-1,i);
//		cout << tri(i-1,i) << '\n';
		sums[i] = (sums[i-1]+s[i])%MOD;
		sumx[i] = (sumx[i-1]+x[i])%MOD;
		sumy[i] = (sumy[i-1]+y[i])%MOD;
	}
	tot = s[N-1];
	int j = 0;
	while(2*s[j] < tot) j++;
	long long ans = 0;
	long long cnt = 0;
	if(j<N-1)
	{
		cnt = N-1-j;
		ans = (ans + getsum(j,N-2,sums))%MOD;
	}
//	cout << 0 << ": " << j << '\n';
	unsigned long long cpoly = s[j];
	for(int i=1;i<N;i++)
	{
		//cout << ans << '\n';
		cpoly -= gentri(i-1,i,j);
		while(2*cpoly < tot)
		{
			cpoly += gentri(i,j,(j+1)%N);
			j = (j+1)%N;
		}
//		cout << i << ": " << j << '\n';
		if(j==i-1) continue;
		cnt += (i-1-j+N)%N;
		if(j<i)
		{
			ans = (ans + (i-j-1)*((tot%MOD)+MOD-(s[i]%MOD)))%MOD;
//			cout << ans << '\n';
			ans = (ans + getsum(j,i-2,sums))%MOD;
//			cout << ans << '\n';
			ans = (ans + (x[i]+MOD)*getsum(j,i-2,sumy))%MOD;
			ans = (ans + MOD - ((y[i]%MOD+MOD)*getsum(j,i-2,sumx))%MOD)%MOD;
		}
		else
		{
			ans = (ans + (N-j)*(MOD-(s[i]%MOD)))%MOD;
			ans = (ans + getsum(j,N-1,sums))%MOD;
//			cout << ans << '\n';
			ans = (ans + MOD - ((y[i]+MOD)*getsum(j,N-1,sumx))%MOD)%MOD;
//			cout << ans << '\n';
			ans = (ans + ((x[i]+MOD)*getsum(j,N-1,sumy))%MOD)%MOD;
//			cout << ans << '\n';
			ans = (ans + (i-1)*((tot%MOD)+MOD-(s[i]%MOD)))%MOD;
			ans = (ans + getsum(0,i-2,sums))%MOD;
			ans = (ans + (x[i]+MOD)*getsum(0,i-2,sumy))%MOD;
			ans = (ans + MOD - ((y[i]+MOD)*getsum(0,i-2,sumx))%MOD)%MOD;
		}
	}
	cout << (2LL*ans+MOD-(((tot%MOD)*(cnt%MOD))%MOD))%MOD << '\n';
}
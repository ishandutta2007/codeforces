#include <iostream>
using namespace std;

bool lg(long long x,long long &ans)
{
	ans = 0;
	while(x>1)
	{
		if((x%2))
			return 0;
		else
			x /= 2;
		ans++;
	}
	return 1;
}

int precomp[1<<20];

int cnt(long long x)
{
	int ans = 0;
	while(x>0)
	{
		if(x%2) ans++;
		x /= 2;
	}
	return ans;
}

long long fst[35];	//first part, with [i] ones, number less
long long scd[35];	//second part, with [i] ones, number anything

int main()
{
	for(int i=0;i<(1<<20);i++)
		precomp[i] = cnt(i);
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long n,t;
	cin >> n >> t;
	n++;
	long long dig;
	if(!lg(t,dig))
	{
		cout << 0 << endl;
		return 0;
	}
	dig++;
	for(int i=0;i<35;i++)
		fst[i] = scd[i] = 0;
	for(int i=0;i<(1<<20);i++)
	{
		if(i>=(n>>20))
			break;
		fst[precomp[i]]++;
	}
	for(int i=0;i<(1<<20);i++)
	{
		if(i>n)
			break;
		scd[precomp[i]]++;
	}
	long long ans = 0;
	for(int i=max(0LL,dig-34LL);i<=min(dig,34LL);i++)
		ans += fst[i]*scd[dig-i];
	for(int i=0;i<35;i++)
		fst[i] = scd[i] = 0;
	fst[precomp[n>>20]]++;
	for(int i=0;i<(1<<20);i++)
	{
		if(i>(n&((1<<20)-1)))
			break;
		scd[precomp[i]]++;
	}
	for(int i=max(0LL,dig-34LL);i<=min(dig,34LL);i++)
		ans += fst[i]*scd[dig-i];
	if(t==1)
		ans--;
	cout << ans << "\n";
	return 0;
}
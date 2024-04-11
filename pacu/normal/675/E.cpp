#include <iostream>
using namespace std;
#define SEG (1<<17)
long long A[SEG];
int N;
int seg[2*SEG],l[2*SEG],r[2*SEG];
long long dp[SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		seg[i] = l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		if(A[seg[2*i]] >= A[seg[2*i+1]]) seg[i] = seg[2*i];
		else seg[i] = seg[2*i+1];
		l[i] = l[2*i], r[i] = r[2*i+1];
	}
}

int low,high;
int getMax(int i)
{
	if((l[i]>high)||(r[i]<low)) return SEG-1;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	int a = getMax(2*i);
	int b = getMax(2*i+1);
	if(A[a] >= A[b]) return a;
	else return b;
}

int main()
{
	cin >> N;
	for(int i=0;i<N-1;i++)
	{
		cin >> A[i];
		A[i]--;
	}
	A[N-1] = N-1;
	init();
	dp[N-1] = 0;
	long long ans = 0;
	for(int i=N-2;i>=0;i--)
	{
		low = i+1, high = A[i];
		int mxloc = getMax(1);
		dp[i] = N-1-i+dp[mxloc]-(A[i]-mxloc);
		ans += dp[i];
	}
	cout << ans << '\n';
}
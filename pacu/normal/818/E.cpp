#include <iostream>
#include <algorithm>
using namespace std;

int N,K;
long long A[100000];
long long ans;

long long prod[100000];

void divide(int l,int r)
{
	if(l==r)
	{
		if(A[l]%K == 0) ans++;
		return;
	}
	int mid = (l+r)/2;
	prod[mid] = A[mid]%K;
	for(int i=mid-1;i>=l;i--)
		prod[i] = (prod[i+1]*A[i])%K;
	prod[mid+1] = A[mid+1]%K;
	for(int i=mid+2;i<=r;i++)
		prod[i] = (prod[i-1]*A[i])%K;
	int j = mid+1;
	while(j <= r && (prod[l]*prod[j])%K) j++;
	int i = l;
	for(;j<=r;j++)
	{
		while(i<mid && (prod[i+1]*prod[j])%K == 0) i++;
		ans += i+1-l;
	}
	divide(l,mid);
	divide(mid+1,r);
}

int main()
{
	cin >> N >> K;
	for(int i=0;i<N;i++)
		cin >> A[i];
	divide(0,N-1);
	cout << ans << '\n';
}
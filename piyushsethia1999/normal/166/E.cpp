#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int 
#define pb push_back
#define m 1000000007
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	ll A[10000001],B[10000001];
	A[1]=0;
	B[1]=3;
	A[2]=3;
	B[2]=B[1]*2;
	for(int i=3;i<=n;i++)
	{
		B[i]=(A[i-1]*3+B[i-1]*2)%m;
		A[i]=B[i-1];
	}
	cout<<A[n];
}
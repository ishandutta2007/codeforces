#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int 
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,A[1000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	sort(A,A+n);
	for(int i=n-1;i>=0;i--)
	{
		int a=sqrt(A[i]);
		if((a*a)!=A[i])
		{
			cout<<A[i];
			break;
		}
	}
}
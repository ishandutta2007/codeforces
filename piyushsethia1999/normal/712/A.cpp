#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF 1<<30

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int A[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}
	for (int i = 0; i < (n-1); ++i)
	{
		cout<<A[i]+A[i+1]<<" ";
	}
	cout<<A[n-1];
}
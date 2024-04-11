#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ul long long int
#define ll unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF 1<<30

using namespace std;
int total[5001][5001];
int main()
{
	fastio;
	int n;
	cin>>n;
	int *A = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}
	for (int i = 0; i < n; ++i)
	{
		total[i][i] = A[i];
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < (n-i); ++j)
		{
			total[j][i+j] = total[j][i+j-1]^total[j+1][i+j];
		}
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < (n-i); ++j)
		{
			total[j][i+j] = max(total[j][i+j],max(total[j][i+j-1], total[j+1][i+j]));
		}
	}
	int q;
	cin>>q;
	int l, r;
	for (int i = 0; i < q; ++i)
	{
		cin>>l>>r;
		l--;
		r--;
		cout<<total[l][r]<<"\n";
	}
}
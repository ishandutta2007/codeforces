#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF (1<<30)

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	A[601]={0};
	int n,x;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>x;
		A[x]=1;
	}
	int count=0;
	for(int i=1;i<601;i++)
	{
		if(A[i])
			count++;
	}
	cout<<count;
}
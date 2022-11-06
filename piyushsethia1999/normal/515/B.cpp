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
	int n,m;
	cin>>n>>m;
	int b,g;
	cin>>b;
	int B[n]={0};
	int G[m]={0};
	int x;
	for (int i = 0; i < b; ++i)
	{
		cin>>g;
		B[g]=1;
	}
	cin>>g;
	for (int i = 0; i < g; ++i)
	{
		cin>>b;
		G[b]=1;
	}
	x = n*m*300;
	for (int i = 0; i < x; ++i)
	{
		b=i%n;
		g=i%m;
		if(B[b]==1||G[g]==1)
		{
			B[b]=1;
			G[g]=1;
		}
	}
	bool r=true;
	for (int i = 0; i < n; ++i)
	{
		if(B[i]==0){
			r=false;
			break;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		if(G[i]==0){
			r=false;
			break;
		}
	}
	if(r){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}
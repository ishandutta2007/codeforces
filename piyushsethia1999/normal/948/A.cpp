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
	int n,m;
	string A[500];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	for(int i=0;i<n;i++){
		for (int j = 0; j < m; ++j)
		{
			if(A[i][j] == '.'){
				A[i][j]='D';
			}
		}
	}
	bool b=false;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(A[i][j] =='W'){
				int x=i-1;
				int y=j;
				if(x>=0){
					if(A[x][y]=='S'){
						b=true;
						break;
					}
				}
				x=i;
				y=j-1;
				
				if(y>=0){
					if(A[x][y]=='S'){
						b=true;
						break;
					}
				}
				x=i+1;
				y=j;

				if(x<n){
					if(A[x][y]=='S'){
						b=true;
						break;
					}
				}
				
				x=i;
				y=j+1;

				if(y<m){
					if(A[x][y]=='S'){
						b=true;
						break;
					}
				}
			}
		}
	}
	if(b){
		cout<<"No";
	}
	else{
		cout<<"Yes\n";
		for (int i = 0; i < n; ++i)
		{
			cout<<A[i]<<"\n";
		}
	}
}
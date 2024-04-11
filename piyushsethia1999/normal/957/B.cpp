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
	string str[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>str[i];
	}
	int R[n] = {0};
	int C[m] = {0};
	int c = 1;
	bool b=true;
	for (int i = 0; i<n&&b; ++i)
	{
		for (int j = 0; j<m; ++j)
		{
			if(str[i][j] == '#'){
				if(R[i]==0&&C[j]==0){
					R[i]=c;
					C[j]=c;
					c++;
				}
				else if(C[j]!=0&&R[i]==0){
					R[i]=C[j];
				}
				
				else if(R[i]!=0&&C[j]==0){
					C[j]=R[i];
				}

				else if(R[i]!=C[j]){
				    b = false;
					break;
				}
			}
		}
	}
	if(b){
		for (int i = 0; i<n&&b; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(R[i]!=0&&C[j]==R[i]&&str[i][j]!='#'){
					b=false;
					
					break;
				}
			}
		}
		if(b)
			cout<<"Yes";
		else{
			cout<<"No";
		}
	}
	else{
		cout<<"No";
	}
}
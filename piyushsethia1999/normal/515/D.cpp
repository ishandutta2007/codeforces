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
string str[2000];
int n,m;
bool isBlockade(int i,int j)
{
	if(str[i][j] == '.')
		return false;
	return true;
}
int x[4] = {-1,0,1,0};
int y[4] = {0,1,0,-1};
int countNeighbour(int i, int j)
{
	int X,Y;
	int c=0;
	for (int k = 0; k < 4; ++k)
	{
		X=i+x[k];
		Y=j+y[k];
		if(X<n&&Y<m&&X>=0&&Y>=0)
		{
			if(str[X][Y] == '.'){
				c++;
			}
		}
	}
	return c;
}
int giveDirection(int i, int j){
	int X,Y;
	for (int k = 0; k < 4; ++k)
	{
		X=i+x[k];
		Y=j+y[k];
		if(X<n&&Y<m&&X>=0&&Y>=0){
			if(str[X][Y] == '.'){
				return k;
			}
		}
	}
}
void traverse(int i,int j)
{
	int g = giveDirection(i,j);
	int X,Y;
	if(g==2){
		str[i][j] = '^';
		str[i+1][j] = 'v';
		i++;
		for (int k = 1; k < 4; ++k)
		{
			X = i+x[k];
			Y = j+y[k];
			if(X<n&&Y<m&&X>=0&&Y>=0){
				if(str[X][Y]=='.'){
					if (countNeighbour(X,Y)==1)
					{
						traverse(X,Y);
					}
				}
			}
		}



	}
	else if(g==3){

		str[i][j] = '>';
		str[i][j-1] = '<';
		j--;
		for (int k = 0; k < 4; ++k)
		{
			X = i+x[k];
			Y = j+y[k];
			if(X<n&&Y<m&&X>=0&&Y>=0){
				if(str[X][Y]=='.'){
					if (countNeighbour(X,Y)==1)
					{
						traverse(X,Y);
					}
				}
			}
		}
	}
	else if(g==0){

		str[i][j] = 'v';
		str[i-1][j] = '^';
		i--;
		for (int k = 0; k < 4; ++k)
		{
			X = i+x[k];
			Y = j+y[k];
			if(X<n&&Y<m&&X>=0&&Y>=0){
				if(str[X][Y]=='.'){
					if (countNeighbour(X,Y)==1)
					{
						traverse(X,Y);
					}
				}
			}
		}

	}
	else{

		str[i][j] = '<';
		str[i][j+1] = '>';
		j++;
		for (int k = 0; k < 3; ++k)
		{
			X = i+x[k];
			Y = j+y[k];
			if(X<n&&Y<m&&X>=0&&Y>=0){
				if(str[X][Y]=='.'){
					if (countNeighbour(X,Y)==1)
					{
						traverse(X,Y);
					}
				}
			}
		}

	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	bool b=true;
	for (int i = 0; i < n; ++i)
	{
		cin>>str[i];
	}
	int calc;
	for (int i = 0; i < n && b; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(isBlockade(i,j))
			{
			}
			else{
				calc = countNeighbour(i,j);
				if(calc==0){
					b=false;
					//cout<<1;
		            /*for (int i = 0; i < n; ++i)
	            	{
			            cout<<str[i]<<"\n";
		            }*/
					//cout<<i<<" "<<j<<"\n";
					break;
				}
				else if(calc==1){
				    //cout<<i<<" "<<j<<"\n";
					traverse(i,j);
				}
				else{

				}
			}
		}
	}
	for (int i = 0; i < n && b; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(isBlockade(i,j)){

			}
			else{
				b=false;
				/*cout<<2;
				for (int i = 0; i < n; ++i)
		        {
			        cout<<str[i]<<"\n";
		        }
				cout<<i<<" "<<j<<"\n";*/
				break;
			}
		}
	}
	if(b){
		for (int i = 0; i < n; ++i)
		{
			cout<<str[i]<<"\n";
		}
	}
	else{
		cout<<"Not unique";
	}

}
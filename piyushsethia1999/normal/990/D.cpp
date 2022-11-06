#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	ll n, a, b;
	cin >> n >> a >> b;
	if (n == 2)
	{
		if(a == 1 && b == 1)
			cout<<"NO\n";
		else if(a == 1 && b == 2){
			cout<<"YES\n01\n10";
		}
		else if(a == 2 && b == 1){
			cout<<"YES\n00\n00";
		}
		else {
			cout<<"NO\n";
		}
	}
	else if(a > 1 && b > 1)
		cout<<"NO";
	else{
		if(a==1&&b==1){
			if(n == 3)
				cout<<"NO\n";
			else{
				cout<<"YES\n";
				std::vector<std::vector<int> > grid(n, std::vector<int> (n, 0));
				for (int i = 0; i < n-1; ++i)
				{
					grid[i][i+1] = 1;
					grid[i+1][i] = 1;
				}
				for (int i = 0; i < n; ++i)
				{
					for (int j = 0; j < n; ++j)
					{
						cout<<grid[i][j];
					}
					cout<<"\n";
				}
			}
		}
		else if(b == 1){
			std::vector<std::vector<int> > grid(n, std::vector<int> (n, 1));
			for (int i = 0; i < n; ++i)
			{
				grid[i][i] = 0;
				for (int j = 0; j < (a-1); ++j)
				{
					grid[j][i] = 0;
					grid[i][j] = 0;
				}
			}
			cout<<"YES\n";
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					cout<<grid[i][j];
				}
				cout<<"\n";
			}
		}
		else {
			cout<<"YES\n";
			std::vector<std::vector<int> > grid(n, std::vector<int> (n, 0));
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < (b-1); ++j)
				{
					if (i != j){
						grid[i][j] = 1;
						grid[j][i] = 1;
					}
				}
			}
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					cout<<grid[i][j];
				}
				cout<<"\n";
			}
		}
	}
}
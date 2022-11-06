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
	/*#ifndef ONLINE_JUDGE
	freopen("/home/piyush/Documents/input.txt", "r", stdin);
	freopen("/home/piyush/Documents/output.txt", "w", stdout);
	#endif/**/
	int n;
	cin>>n;
	if(n>=6) {
		cout<<"1 2"<<"\n";
		cout<<"2 3"<<"\n";
		cout<<"2 4"<<"\n";
		cout<<"4 5"<<"\n";
		cout<<"4 6"<<"\n";
		for (int i = 7; i <= n; ++i)
		{
			cout<<i<<" "<<2<<"\n";
		}
	}
	else{
		cout<<-1<<"\n";
	}
	for (int i = 1; i < n; ++i)
	{
		cout<<i<<" "<<i+1<<"\n";
	}
}
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
	int m,s;
	cin>>m>>s;
	if(s == 0 && m == 1)
	{
		cout<< "0 0";
		return 0;
	}
	else if(s == 1) {
	    m--;
		cout<<1;
		for (int i = 0; i < m; ++i)
		{
			cout<<0;
		}
		cout<<" ";
		cout<<1;
		for (int i = 0; i < m; ++i)
		{
			cout<<0;
		}
		return 0;
	}
	
	if(s == 0||9*m<s){
		cout<<"-1 -1";
		return 0;
	}
	
	int N=m;
	int S=s;
	int nine;
	if((s-(m-1)*9)<=1) {
		cout<<1;
		s--;
		m--;
		nine = s/9;
		if(s%9) {
			for(int i=0; i<(m-1-nine); i++)
				cout<<0;
			cout<<s%9;
			for (int i = 0; i < nine; ++i)
			{
				cout<<9;
			}
		}
		else {
			for (int i = 0; i < (m-nine); ++i)
			{
				cout<<0;
			}
			for (int i = 0; i < nine; ++i)
			{
				cout<<9;
			}
		}
	}
	else {
		cout<<(s-(m-1)*9);
	 	m--;
	 	for (int i = 0; i < m; ++i)
	 	{
	 		cout<<9;
	 	}
	}
	cout<<" ";
	m = N;
	s = S;
	nine = s/9;
	for(int i=0;i<nine;i++)
	{
		cout<<9;
	}
	if(s%9){
		cout<<s%9;
		for(int i = 0; i < (m-nine-1); i++)
			cout<<0;
	}
	else{
		for (int i = 0; i < (m-nine); ++i)
		{
			cout << 0;
		}
	}
}
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

template <typename T>
void input(T A[], int n)
{
	for (int i = 0; i < n; ++i) {
		cin>>A[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("/home/piyush/Documents/input.txt", "r", stdin);
	freopen("/home/piyush/Documents/output.txt", "w", stdout);
	#endif/**/
	string s;
	cin>>s;
	int n = 0;
	int p = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i] == 'o')
			n++;
		else
			p++;
	}
	if(n == 0)
		cout<<"YES";
	else if(p%n)
		cout<<"NO";
	else
		cout<<"YES";
}
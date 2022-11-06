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
int mod(int x) {
	return (x>0 ? x:-x);
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
	int n;
	cin>>n;
	std::vector<int> v((n/2));
	for (int i = 0; i < (n/2); ++i)
	{
		cin>>v[i];
	}
	int counteod = 0;
	int countev = 0;
	sort(v.begin(), v.end());
	for (int i = 1; i <= (n/2); ++i)
	{
		countev += mod(2*i - v[i-1]);
		counteod += mod(2*i - 1 - v[i-1]);
	}
	counteod = min(counteod, countev);
	cout<<counteod;
}
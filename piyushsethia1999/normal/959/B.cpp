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
		#ifndef ONLINE_JUDGE
		freopen("/home/piyush/Documents/input.txt", "r", stdin);
		freopen("/home/piyush/Documents/output.txt", "w", stdout);
		#endif/**/
		ll n,k,m;
		cin>>n>>k>>m;
		string s[100001];
		ll grpno[100001];
		std::map<string, ll> map;
		for (ll i = 1; i <= n; ++i)
		{
			cin>>s[i];
			map[s[i]] = i;
		}
		ll A[100001];
		for (ll i = 1; i <= n; ++i)
		{
			cin>>A[i];
			//cout<<s[i]<<" "<<map[s[i]]<<" "<<A[i]<<"\n";
		}
		ll x,pos;
		ll min;
		ll minimumCost[100001];
		for (ll i = 0; i < k; ++i)
		{
			cin>>x;
			min=1000000001;
			for (ll j = 0; j < x; ++j)
			{
				cin>>pos;
				if(A[pos]<min)
					min = A[pos];
				grpno[pos] = i;
			}
			minimumCost[i] = min;
		}
		ll total=0;
		for (ll i = 0; i < m; ++i)
		{
			cin>>s[0];
			total+=minimumCost[grpno[map[s[0]]]];
		}
		cout<<total;
	}
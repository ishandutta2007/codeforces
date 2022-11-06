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
		#endif*/
		ll a, b;
		cin >> a >> b;
		ll c, d, e;
		for (ll i = 60; i >= 0; --i)
		{
			c = (static_cast<long long int>(1) << i);
			d = a+(c-(a%c));
			if(d>=a&&d<=b)
			{
				e = d^(d-1);
				cout << e ;
				return 0;
			}
		}

		cout<<0;
		return 0;
	}
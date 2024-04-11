#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#endif
	ll n; cin >> n;
	ll A[50];
	ll cost[5];
	for (int o = 0; o < n; ++o) { cin >> A[o]; }
	for (int o = 0; o < 5; ++o) { cin >> cost[o]; }
	ll rem = 0;
	ll count[5] = {0};
	int indexofitemtobebought;
	for (int i = 0; i < n; ++i)
	{
		rem += A[i];
		indexofitemtobebought = -1;
		for (int j = 0; j < 5; ++j)
		{
			if(rem >= cost[j])
				indexofitemtobebought = j;
		}
		while(indexofitemtobebought >= 0) {
			count[indexofitemtobebought] += rem/cost[indexofitemtobebought];
			rem = rem%cost[indexofitemtobebought];
			indexofitemtobebought--;
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		cout << count[i] << " ";
	}
	cout<<"\n"<<rem;
}
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
	int n;
	cin>>n;	
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	std::vector<std::pair<int, int> > sorted;
	int size = 1;
	std::vector<int> d(n);
	d[n-1] = -1;
	sorted.pb(mp(v[n-1], n-1));
	for (int i = n-2; i >= 0; --i)
	{
		if(sorted[size-1].first > v[i])
		{
			sorted.pb(mp(v[i], i));
			size++;
			d[i] = -1;
		}
		else if(sorted[size-1].first == v[i]) {
			d[i] = -1;
		}
		else {
			int start = 0;
			int end = size-1;
			while(start < end)
			{
				int mid = (start + end)/2;
				if(sorted[mid].first >= v[i]){
					start = mid + 1;
				}
				else {
					end = mid;
				}
			}
			d[i] = sorted[end].second-i-1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<d[i]<<" ";
	}
}
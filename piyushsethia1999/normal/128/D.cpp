#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int max(std::vector<int>& v, int I)
{
	int p = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i] > p && i != I)
			p = v[i];
	}
	return p;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n;
	cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	a.pb(a[0]);
	a.pb(a[n-1]);
	sort(a.begin(), a.end());
	print(a, a.size(), n);
	int prev = a[0] - 1;
	int prevextra = 0;
	bool b = true;
	for (int i = 0; i < n+2;)
	{
		if(prev + 1 != a[i]){
			b = false;
			break;
		}
		int t = 0;
		while(i < n+2 && a[i] == prev + 1) {
			t++;
			i++;
		}
		t -= (prevextra+2);
		if(t < 0) {
			b = false;
			break;
		}
		prevextra = t;
		prev++;
	}
	if(prevextra)
		b = false;
	if(!b)
		cout << "NO";
	else
		cout << "YES";
}
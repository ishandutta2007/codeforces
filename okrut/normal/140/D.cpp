#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n;
	scanf ("%d", &n);
	vector <int> T(n);
	for (int &t: T) scanf ("%d", &t);
	sort(T.begin(), T.end());
	
	int before = 6*60 - 10;
	int after = 6*60;
	
	int tasks = 0, penalty = 0, curr = 0;
	
	for (int t: T)
	{
		curr += t;
		
		if (curr > before + after) break;
		tasks++;
		if (curr > before) penalty += curr - before; 
	}
	printf ("%d %d\n", tasks, penalty);
	
}
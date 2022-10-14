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
	
	int n, k;
	scanf ("%d %d", &n, &k);
	vector <ll> C(n);
	for (ll &c: C) scanf ("%lld", &c);
	sort(C.begin(), C.end());
	
	ll res = 0;
	ll sum = 0;
	while (!C.empty() and sum+C.back() >= 0LL) {
		res += sum;
		sum += C.back();
		C.pop_back();
	}
	
	n = C.size();
	k++;
	ll t = -1;
	rep(i,0,n) 
	{
		if (i%k==0) t++;
		res += t * C[i];
	}
	t++;
	res += t * sum;
	
	printf ("%lld\n", res);
}
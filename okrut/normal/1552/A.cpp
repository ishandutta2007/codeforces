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
	ios_base::sync_with_stdio(false);
	int tc;
	cin>>tc;
	
	rep(q,0,tc) {
		int n;
		string s, t;
		cin>>n >>s;
		
		t = s;
		sort(t.begin(), t.end());
		
		int k = 0;
		rep(i,0,n) if (s[i] != t[i]) k++;
		
		printf ("%d\n", k);
	}
}
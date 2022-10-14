#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i < b; i++)
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
	int t;
	cin>>t;
	rep(q,0,t) {
		string s;
		cin>>s;
		
		int zero_segs = 0;
		char prv = 'z';
		for (char c: s) {
			if (c == '0' and prv != '0') zero_segs++;
			prv = c;
		}
		
		if (zero_segs == 0) printf ("0\n");
		else if (zero_segs == 1) printf ("1\n");
		else printf ("2\n");
		
		
	}
}
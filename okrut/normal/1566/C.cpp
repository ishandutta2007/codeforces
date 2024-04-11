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
		int n; string s1, s2;
		cin>>n >>s1 >>s2;
		
		int res = 0;
		int state = 0;
		rep(i,0,n) {
			int x = (1 << (s1[i] - '0')) | (1<< (s2[i] - '0'));
			
			if (state == 0) {
				state = x;
			} else if (state == 1) {
				if (x & 1) {
					state = x;
					res++;
				} else {
					state |= x;
				}
			} else if (state == 2) {
				state |= x;
			}
			
			if (state == 3) {
				res += 2;
				state = 0;
			}
		}
		
		if (state == 1) res++;
		
		printf ("%d\n", res);
	}
}
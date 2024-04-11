#include <bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5+10;
char D[N], A[N];

int main()
{
	//ios_base::sync_with_stdio(false);
	
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n;
		scanf ("%d", &n);
		
		scanf("%s", D);
		
		
		if (D[0] < '9') {
			
			rep(i,0,n) A[i] = '9' - (D[i] - '0');
			
		} else {
			
			int carry = 0;
			for (int i = n-1; i >=0; i--) {
				int val = D[i] - '0' + carry;
				carry = 0;

				switch(val) {
				case 0:
					A[i] = '1';
					break;
				case 1:
					A[i] = '0';
					break;
				default:
					A[i] = '0' + 11 - val;
					carry = 1;
					break;
				}
			}
		}
		
		A[n] = 0;
		printf("%s\n", A);
		
	}
}
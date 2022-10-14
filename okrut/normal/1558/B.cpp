#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 4e6+2;

int Suf[N*2];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, m;
	scanf ("%d %d", &n, &m);
	
	int s = 1, here = 1;
	Suf[n] = 0;
	
	for (int i = n - 1; i > 0; i--) {
		Suf[i] = (Suf[i+1] + here) % m;
		
		here = s;
		
		
		rep(y,2,n+1) {
			if (y * i > n) break;
			
			here = (here + (m + Suf[y*i-1] - Suf[y*(i+1)-1]) % m) % m;
		}
		
		
		s = (s + here) % m;
		
	}
	
	printf ("%d\n", here);
	
}
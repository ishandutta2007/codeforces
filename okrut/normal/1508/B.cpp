#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	
	rep(q,0,t) {
		
		int n; ll k;
		scanf ("%d %lld", &n, &k);
		
		if (n < 62 and (1LL << (n-1)) < k) {
			printf ("-1\n");
			continue;
		}
		
		int num = 1;
		
		while (num <= n) {
			
			int cnt = n - num;
			
			debug ("Do cnt = %d for k = %lld\n", cnt, k);
			
			if (cnt > 62 || cnt == 0) printf ("%d ", num++);
			else
			{
				
				while (cnt > 0 and k > (1LL << (cnt - 1))) {
					k -= (1LL << (cnt - 1));
					cnt--;
				}
				
				
				for (int x = n - cnt; x >= num; x--) printf ("%d ", x);
				num = n - cnt + 1;
			}
		}
		
		printf ("\n");
	}
}
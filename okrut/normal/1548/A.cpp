#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5+1;

int Up[N], Down[N];


int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, m;
	scanf ("%d %d", &n, &m);
	rep(i,0,m) {
		int a, b;
		scanf ("%d %d", &a, &b);
		if (a > b) swap(a,b);
		Up[a]++;
		Down[b]++;
	}
	
	int cnt = 0;
	rep(i,1,n+1) {
		if (Up[i] == 0) cnt++;
	}
	
	int q;
	scanf ("%d", &q);
	rep(t,0,q) {
		int x, a, b;
		scanf ("%d", &x);
		if (x == 3) {
			printf ("%d\n", cnt);
			continue;
		}
		scanf ("%d %d", &a, &b);
		if (a > b) swap(a,b);
		
		if (Up[a] == 0) cnt--;
		
		int y;
		if (x == 1) y = 1;
		else y = -1;
		
		Up[a]+= y;
		Down[b]+= y;
		
		if (Up[a] == 0) cnt++;
	}
}
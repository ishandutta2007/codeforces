#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e3+5;
int State[N], Target[N];
int n;

int turnOn ()
{
	vector <int> vec;
	rep(i,0,n) if (Target[i] > State[i]) 
	{
		State[i] = 1;
		vec.pb(i);
	}
	int k = vec.size();
	printf ("%d ", k);
	for (int v: vec) printf ("%d ", v+1);
	printf ("\n");
	fflush(stdout);
	return k;
}

void read (int k)
{
	int x;
	scanf ("%d", &x);
	if (x==-1) exit(0);
	
	x--;
	rep(i,0,k)
	{
		State[(x+i)%n] = 0;
	}
}
void finish()
{
	printf ("0\n");
	exit(0);
}
int main ()
{
	//ios_base::sync_with_stdio(false);
	
	scanf ("%d", &n);
	
	int myK = 0;
	int best = 0;
	
	rep(ck,1,n+1)
	{
		int res = 0;
		rep(i,0,n-1) if (i%ck < ck-1) res++;
		
		res = max(0, res - ck+1);
		
		if (res > best)
		{
			best = res;
			myK = ck;
		}
	}
	
	debug ("my best is %d\n", best);
	
	if (best==0) finish();
	
	rep(i,0,n-1) if (i%myK < myK-1) Target[i] = 1;
	
	for(;;)
	{
		int cnt = 0;
		rep(i,0,n) cnt += State[i];
		if (cnt >= best) finish();
		
		int k = turnOn();
		if (k==0) break;
		read(k);
	}
}
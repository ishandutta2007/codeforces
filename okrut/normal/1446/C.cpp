#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

vector <int> tab;

int longest (int k, int l, int r)
{
	if (l>r) return 0;
	
	if (l==r) return 1;
	
	int mid;
	for (mid=l; mid <= r; mid++) if (tab[mid]&(1<<k)) break;
	mid--;
	
	int a = longest(k-1, l, mid);
	int b = longest(k-1, mid+1, r);
	
	if (mid>=l) b++;
	if (mid<r) a++;
	return max(a,b);
	 
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n;
	scanf ("%d", &n);
	tab.resize(n);
	for (int &a: tab) scanf ("%d", &a);
	sort(tab.begin(), tab.end());
	
	int res = longest(29,0,n-1);
	
	printf ("%d\n", n - res);
}
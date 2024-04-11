#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug // 
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	vector <int> tab(n);
	for (int &a: tab) scanf ("%d", &a);
	vector <int> rob = tab;
	
	sort(rob.begin(), rob.end());
	
	rep(i,1,n) if (rob[i]==rob[i-1]) 
	{
		printf ("-1\n");
		return 0;
	}
	
	map <int, int> mapa;
	rep(i,0,n) mapa[rob[i]] = rob[(i+1)%n];
	
	for (int r: tab) printf ("%d ", mapa[r]);
	printf ("\n");
}
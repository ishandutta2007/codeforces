#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	ios_base::sync_with_stdio(false);
	string s;
	int n;
	cin >>n >>s;
	int zer = 0, jed = 0;
	rep(i,0,n) 
	{
		if (s[i]=='r') zer++;
		if (s[i]=='n') jed++;
	}
	rep(i,0,jed) cout<<"1 ";
	rep(i,0,zer) cout<<"0 ";
	cout<<"\n";
}
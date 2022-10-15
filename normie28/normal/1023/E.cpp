#include<bits/stdc++.h>
#define ll long long;
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int n; cin >> n;
	string res,revres;
	for(int i=1,x=1,y=1;i<n;i++)
	{
		cout << "? " << x+1 << ' ' << y << ' ' << n << ' ' << n << endl;
		char c; cin >> c>>c;
		if(c == 'E') {cin>>c; res += "D"; x++; }
		else { res += "R"; y++; }
	}
	for(int i=1,x=n,y=n;i<n;i++)
	{
		cout << "? 1 1 " << x << ' ' << y-1 << endl;
		char c; cin >> c>>c;
		if(c == 'E') {cin>>c; revres = "R" + revres; y--; }
		else { revres = "D" + revres; x--; }
	}
	 cout << "! " << res << revres << endl;
}
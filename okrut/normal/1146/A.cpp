#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi fist
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

int main ()
{
	int a=0;
	string s;
	cin>>s;
	rep(i,0,(int)s.size()) if (s[i]=='a') a++;
	cout <<min((int)s.size(), a*2-1) <<"\n";
	
}
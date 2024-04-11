#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

vector <int> res;
int n;
int main ()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	string s;
	cin>>s;
	
	int d=0;
	rep(i,0,n)
	{
		if (s[i]=='(') 
		{
			d++;
			
			if (d%2==0) s[i]='0';
			else s[i]='1';
		}
		else 
		{
			if (d%2==0) s[i]='0';
			else s[i]='1';
			
			d--;
		}
		
		
	}
	cout<<s <<"\n";
	
}
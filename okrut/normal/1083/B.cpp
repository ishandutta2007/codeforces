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
string s, t;
int main ()
{
	bool roz=false; //czy prefiksy sa rozne
	int n, k;
	
	cin>>n >>k >>s >>t;
	ll res=n; //tyle na pewno
	ll x=0; //tyle slow pomiedzy
	k-=2; //tyle slow zostalo do wytworzenia
	rep(i,0,n) if (k>0)
	{
		if (x>k) x=k; //tyle nowych slow tworze
		res+=(ll)x*(ll)(n-i);
		k-=x;
		x*=2;
		if (roz)
		{
			if (s[i]=='a') if (k>0)
			{
				x++;
				k--;
				res+=(ll)(n-i);
			}
			if (t[i]=='b') if (k>0)
			{
				x++;
				k--;
				res+=(ll)(n-i);
			}
		}
		if (s[i]!=t[i]) 
		{
			if (!roz) res+=n-i;
			roz=true;
		}
	}
	cout<<res <<"\n";
}
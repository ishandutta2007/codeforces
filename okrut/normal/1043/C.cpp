#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
int n;
string s;
vector <int> wyn;

int main ()
{
	//ios_base::sync_with_stdio(false);
	cin>>s;
	n=s.size();
	wyn.resize(n);
	int sort=0; //ma byc posortowane
	for (int i=n-1; i>=0; i--)
	{
		if (sort==0) wyn[i]=(1-(s[i]-'a'));
		else wyn[i]=(s[i]-'a');
		if (wyn[i]==1) sort=1-sort;
	}
	rep(i,0,n) cout<<wyn[i] <<" ";
	cout<<"\n";
}
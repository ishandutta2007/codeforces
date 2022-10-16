// Example program
#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define lli long long int
//#define cin in
//#define cout out
int inf = pow(10,9); 
int main()
{
	lli n,f;
	cin>>n>>f;
	vector<lli > sec;
	lli cem = 0;
	fori(n)
	{
		lli a,b;
		cin>>a>>b;
		cem += min(a,b);
		lli eded = 0;
		if(a<b)
		{
			eded = (b-a);
			eded = min(eded,a);
		}
		sec.push_back(eded);
	}
	sort(sec.begin(),sec.end());
	for(lli i=n-1; i>=n-f; i--){
		cem+=sec[i];
	}
	cout<<cem;
}
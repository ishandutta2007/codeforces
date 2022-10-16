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
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int main()
{
	int n;
	double k;
	cin>>n>>k;
	double cem = 0;
	fori(n)
	{
		int eded;
		cin>>eded;
		cem+=eded;
	}
	double bol = n;
	double orta = cem/bol;
	int say = 0;
	while(orta<k-0.5)
	{
		++say;
		cem+=k;
		++bol;
		orta = cem/bol;
	}
	cout<<say;
}
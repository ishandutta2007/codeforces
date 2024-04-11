#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define lli long long int
int MAX = pow(10,2);
int inf = pow(10,9);
int modulo = pow(10,9)+7;
double eps = 1e-7;
int main()
{
	int n,t,k,d;
	cin>>n>>t>>k>>d;
	int time1 = 0;
	int say = 0;
	while(say<n)
	{
		say+=k;
		time1+=t;
	}
	int time2 = d+t;
	if(time1<=time2)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES";
	}
}
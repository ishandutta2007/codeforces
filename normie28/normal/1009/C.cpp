#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll h, n, i;
 long double x,d,mean=0;
	cin>>n>>h;
	for (i=0;i<h;i++)
	{
	cin>>x>>d;
	mean+=x*n;
	if (d>=0) mean+=d*(n-1)*n/2;
	else if (n%2)
	{
	mean+=d*((n/2)+1)*(n/2);
	}
	else
	{
	mean+=d*(((n/2)+1)*(n/2)-(n/2));
	}
	}
	cout<<fixed<<setprecision(12)<<mean/n;
}
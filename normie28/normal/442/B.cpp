#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
double p[101],s,pd=1;
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>p[i];
	sort(p,p+n,greater<double>());
	double prob=p[0],suc=p[0],fail=1-p[0];
	for(int i=1;i<n;i++)
	{
		suc=suc*(1-p[i])+fail*p[i];
		fail=fail*(1-p[i]);
		prob=max(prob,suc);
	}
	cout<<fixed<<setprecision(13)<<prob<<endl;
}
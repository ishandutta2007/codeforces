#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> aa;
ll all[200001];
int main(){
  ll h, n, i, a, b;
 long double x,d,mean=0;
	cin>>a>>b;
	n=0;
	while (n*(n+1)/2<=a+b) n++;
	n--;
	i=n;
	while ((a>=i)and(i)) {aa.push_back(i); a-=i; i--;}
	if ((a)and(i)) aa.push_back(a);
	cout<<aa.size()<<endl;
	for (i=0;i<aa.size();i++) {cout<<aa[i]<<' '; all[aa[i]]++;}
 	cout<<endl<<n-aa.size()<<endl;
	for (i=1;i<=n;i++) if (!all[i]) cout<<i<<' ';
}
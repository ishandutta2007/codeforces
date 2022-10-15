#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a,b,d;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	d=__gcd(n*m,k);
	a=__gcd(d,n);
	b=d/a;
	n/=a;
	m/=b;
	k/=d;
	if (k>2) cout<<"NO";
	else if (k==2) cout<<"YES"<<endl<<0<<' '<<0<<endl<<n<<' '<<0<<endl<<0<<' '<<m;
	else if (a>1) cout<<"YES"<<endl<<0<<' '<<0<<endl<<n*2<<' '<<0<<endl<<0<<' '<<m;
	else cout<<"YES"<<endl<<0<<' '<<0<<endl<<n<<' '<<0<<endl<<0<<' '<<m*2;
}
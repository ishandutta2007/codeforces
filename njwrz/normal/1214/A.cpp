#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
int main(){
	int a,b,m;
	cin>>m>>a>>b;
	b*=5;
	int t=a*b/__gcd(a,b);
	m=min(m,(m%t)+t);
	int ans=1000000000;
	for(int i=0;i<=m;i+=a){
		ans=min(ans,(m-i)%b);
	}
	cout<<ans;
	return 0;
}
#include<iostream>
#include<math.h>

using namespace std;

typedef long long ll;

int main(){
	ll n,m,a;
	cin>>n>>m>>a;
	cout<<(ll)ceil((double)n/a)*(ll)ceil((double)m/a)<<endl;
	return 0;
}
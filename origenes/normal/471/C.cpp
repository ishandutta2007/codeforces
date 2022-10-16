#include <iostream>
using namespace std;
typedef long long ll;
ll n;
int main(){
	cin>>n;
	ll L=0, R=1<<30LL;
	while(L+1<R){
		ll M=L+R>>1;
		if(M*(M+1)/2*3-M<=n) L=M;
		else R=M;
	}
	L-=(L+n)%3;
	cout<<(L+2)/3<<endl;
	return 0;
}
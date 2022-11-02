#include <iostream>
using namespace std;
int main(){
	long long int n,m,a,N,M;
	cin>>n>>m>>a;
	N=n/a;
	M=m/a;
	if (n%a!=0){
		N+=1;
	}
	if (m%a!=0){
		M+=1;
	}
	cout<<M*N;
}
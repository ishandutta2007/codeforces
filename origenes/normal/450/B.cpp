#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
ll A[2][2], B[2][2], C[2][2], D[2][2];
void mul(){
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++){
			A[i][j]=0;
			for(int k=0; k<2; k++){
				A[i][j]+=B[i][k]*C[k][j];
				A[i][j]%=MOD;
			}
		}
}
void fast_pow(ll n){
	for(int i=0; i<2; i++)
		A[i][i]=1;
	C[0][0]=1; C[0][1]=-1;
	C[1][0]=1; C[1][1]=0;
	while(n){
		if(n&1){
//			A*=B;
			for(int i=0; i<2; i++)
				for(int j=0; j<2; j++)
					B[i][j]=A[i][j];
			mul();
		}
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				B[i][j]=C[i][j];
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				D[i][j]=A[i][j];
		mul();
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				C[i][j]=A[i][j];
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				A[i][j]=D[i][j];
		n>>=1;
	}
}
int main(){
	ll x, y, n;
	cin>>x>>y>>n;
	if(n==1LL){
		cout<<((x%MOD)+MOD)%MOD<<endl;
		return 0;
	}
	fast_pow(n-2);
	cout<<((A[0][0]*y+A[0][1]*x)%MOD+MOD)%MOD<<endl;
	return 0;
}
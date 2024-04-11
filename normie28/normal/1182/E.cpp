#include<iostream>
using namespace std;
long long defmod=1000000007;
long long p,q;
long long g[5][5];
void multiply(long long a[5][5],long long b[5][5],long long mod){
	long long c[5][5]={0};
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%mod)%mod;
			}
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			a[i][j]=c[i][j];
		}
	}
 
}
 
long long powermod(long long a,long long b,long long mod){
	if(b==0){
		return 1;
	}
	else{
		if(b%2 == 1){
			return (a*powermod((a*a)%mod,b/2,mod))%mod;
		}
		else{
			return powermod((a*a)%mod,b/2,mod);
		}
	}
}
 
void power(long long  a[5][5],long long n,long long mod){
	
	if(n<=1){
		return;
	}
	else if(n%2==0){
		power(a,n/2,mod);
		multiply(a,a,mod);
	    
	}
	else{
		power(a,n/2,mod);
		multiply(a,a,mod);
		
		multiply(a,g,mod);
		
    }    
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	// Fast I/O
	long long n,f1,f2,f3,c;
	cin>>n>>f1>>f2>>f3>>c;
	
	
	long long A[5][5]={{0,1,0,0,0},{0,0,1,0,0},{1,1,1,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			g[i][j]=A[i][j];
	    }
	}
	power(A,n-1,defmod-1);
	
	long long exp1=A[0][0];
	long long exp2=A[0][1];
	long long exp3=A[0][2];
	
	long long B[5][5]={{0,1,0,0,0},{0,0,1,0,0},{1,1,1,2,-6},{0,0,0,1,1},{0,0,0,0,1}};
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			g[i][j]=B[i][j];
	    }
	}
	power(B,n-1,defmod-1);
	long long exp4=(B[0][3]*4+B[0][4])%(defmod-1);
	long long ans=1;
	ans=(ans*powermod(f1,exp1,defmod))%defmod;
	ans=(ans*powermod(f2,exp2,defmod))%defmod;
	ans=(ans*powermod(f3,exp3,defmod))%defmod;
	ans=(ans*powermod(c,exp4,defmod))%defmod;
	cout<<ans;
}
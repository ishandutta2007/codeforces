#include<bits/stdc++.h>
using namespace std;
typedef double ld;
int n,m,k;
int main(){
	cin>>n>>m>>k;
	if(k>=m)return cout<<1,0;
	ld res=1;
	int a,b,i;
	a=m-k,b=n+1;
	for(i=1;i<=k+1;++i,++a,++b){
		res=res*a/b;
	}
	cout<<fixed<<setprecision(10)<<(0.0>1-res?0.0:1-res);
}
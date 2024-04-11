#include<bits/stdc++.h>
#define int long long
#define cl (fflush(stdout))
using namespace std;
int a[27][27];
int b[27][27];
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=base*x;
		x=x*x;
		k>>=1;
	}
	return base;
}
int n;
int q;
long long x;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i+=2){
		a[i][1]=ksm(2,i);
		b[i][1]=i;
	}
	for(int i=1;i<=n;i+=2){
		for(int k=2;k<=n;k++){
			b[i][k]=b[i][k-1]+1;
			a[i][k]=ksm(2,b[i][k]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			cout<<a[i][k]<<" ";
		}
		puts("");
	}
	cl;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>x;
		int qx=1;int qy=1;
		for(int k=1;k<=2*n-1;k++){
			printf("%lld %lld\n",qx,qy);
			if(qx&1){
				if((1ll<<(b[qx][qy+1]))&x)qy++;
				else{
					qx++;
				}
			}
			else{
				if((1ll<<(b[qx+1][qy]))&x)qx++;
				else{
					qy++;
				}
			}
		}
		puts("");
		cl;
	}
	return 0;
}
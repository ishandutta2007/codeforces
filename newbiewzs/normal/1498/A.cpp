#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
#define int long long
int T,n;
int gcd(int x,int y){
	if(!x)return y;
	else return gcd(y%x,x);
}
signed main(){
//	cout<<gcd(114,514); 
	cin>>T;
/*	for(int i=1;i<=100000;i++){
		int x=i;
		int summ=0;
		while(x){
			summ+=x%10;
			x/=10;
		}
		if(gcd(summ,i)>1){
			cout<<i<<endl;
		}
	}*/
	while(T--){
		cin>>n;
		while(1){
			int u=n;
			int summ=0;
			while(u){
				summ+=u%10;
				u/=10;
			}
			if(gcd(n,summ)>1){
				printf("%lld\n",n);
				break; 
			}
			n++;
		}
	}
	return 0;
}
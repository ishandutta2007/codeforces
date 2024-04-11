#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
int T,n,m;
const int N=2e5+55;
int gcd(int x,int y){
	if(!x)return y;
	else return gcd(y%x,x);
}
int main(){
	T=read();
	while(T--){
		cin>>n>>m;
		if(n%2==1){
			cout<<1<<" "<<(n-1)/2<<" "<<(n-1)/2<<endl; 
		}
		else{
			if(n%4==0){
				cout<<n/4<<" "<<n/4<<" "<<n/2<<endl;
			}
			else{
				cout<<2<<" "<<(n)/2-1<<" "<<(n)/2-1<<endl;
			}
		}
	}
	return 0;
}
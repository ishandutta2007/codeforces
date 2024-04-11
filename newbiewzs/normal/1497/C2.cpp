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
int a[N]; 
int tong[N];
int main(){
	T=read();
	while(T--){
		n=read();m=read();
		m-=3;
		for(int i=1;i<=m;i++){
			printf("%d ",1);
		}
		n-=m;
		if(n%2==1){
			printf("%d %d %d\n",1,n/2,n/2);
		}
		else{
			if(n%4==0){
				printf("%d %d %d\n",n/4,n/4,n/2);
			}
			else{
				printf("%d %d %d\n",2,n/2-1,n/2-1);
			}
		}
	}
	return 0;
}
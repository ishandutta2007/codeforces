#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,m,x;
int a[201];
inline void check(){
	for(int i=1;i<=n+m;i++){
		if(a[i]){
			puts("Ashish");
			return;
		}
	}
	puts("Jeel");
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>x;
				a[i+j]^=x;
			}
		}
		check();
	}
}
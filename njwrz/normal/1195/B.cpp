#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
inline int in(){
	int x=0,f=1;
	char ch;
	do{
		ch=getchar();
		if(ch=='-')
		f=-1;
	}while(ch>'9'||ch<'0');
	do{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}while(ch<='9'&&ch>='0');
	return f*x;
}
int main(){
	long int n=in(),m=in();
	long int t=0,l=0;
	while(1){
		t++;
		l+=t;
		if(l-n+t==m){
			cout<<l-m;return 0;
		}
	} 
	return 0;
}
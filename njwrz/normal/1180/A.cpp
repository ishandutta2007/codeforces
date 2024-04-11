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
	int n=in();
	int m=n*2-1;
	cout<<(m+1)*n-m;
	return 0;
}
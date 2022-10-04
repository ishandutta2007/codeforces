#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,q;
char str[100005];

int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	int cnt=0;
	F(i,1,n) if(str[i]=='1') ++cnt;
	int g=0;
	F(i,1,n){
		if(str[i]=='0') putchar('0');
		if(str[i]=='2'){
			if(!g)
				while(cnt--) putchar('1');
			g=1;
			putchar('2');
		}
	} if(!g) while(cnt--) putchar('1');
	return 0;
}
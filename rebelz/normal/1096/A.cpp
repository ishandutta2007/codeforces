#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int t,x,y;

int main(){
	t=readint();
	while(t--){
		x=readint(); y=readint();
		printf("%d %d\n",x,2*x);
	}
	return 0;
}
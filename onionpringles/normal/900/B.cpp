
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<101010;i++){
		a*=10;
		int x=a/b;
		a%=b;
		if(x==c)return !printf("%d\n",i+1);
	}
	return puts("-1"),0;
}
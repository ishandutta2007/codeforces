#include<bits/stdc++.h>
using namespace std;
int b[108];
int main(){
	int x;
	scanf("%*d");
	while(~scanf("%d",&x)) ++b[x];
	int y=0;
	for(int i=1;i<=100;++i) y=max(y,b[i]);
	printf("%d",y);
	return 0;
}
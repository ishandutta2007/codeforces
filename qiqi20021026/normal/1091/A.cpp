#include<bits/stdc++.h>

using namespace std;

int a,b,c,ans;

int main(){
	scanf("%d%d%d",&a,&b,&c);
	int x=min(a,min(b-1,c-2));
	if (x>0) ans=x*3+3;
	printf("%d\n",ans);
	
	return 0;
}
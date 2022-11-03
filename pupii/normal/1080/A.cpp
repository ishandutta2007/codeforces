#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main(){
	int n=gi(),k=gi();
	printf("%d\n",(n*2+k-1)/k+(n*5+k-1)/k+(n*8+k-1)/k );
	return 0;
}
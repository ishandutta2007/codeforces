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
int x[51],y[51];
int main(){
	int n=gi();
	for(int i=1;i<=n;++i)x[i]=gi(),y[i]=gi(),gi();
	for(int i=1;i<n;++i)putchar('(');
	for(int i=1;i<=n;++i){
		printf("(%d*((1-abs((t-%d)))+abs((1-abs((t-%d))))))",x[i]/2,i,i);
		if(i!=1)printf(")");
		printf("%c","+\n"[i==n]);
	}
	for(int i=1;i<n;++i)putchar('(');
	for(int i=1;i<=n;++i){
		printf("(%d*((1-abs((t-%d)))+abs((1-abs((t-%d))))))",y[i]/2,i,i);
		if(i!=1)printf(")");
		printf("%c","+\n"[i==n]);
	}
	return 0;
}
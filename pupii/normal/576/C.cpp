#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
struct yyb{int x,y,i;}a[1000010];
il bool cmp(const yyb&a,const yyb&b){
	if(a.x==b.x){
		if(a.x&1)return a.y<b.y;
		else return a.y>b.y;
	}return a.x<b.x;
}
int main(){
	int n=gi(),m=sqrt(1000000);
	for(int i=1;i<=n;++i)a[i].x=gi()/m,a[i].y=gi(),a[i].i=i;
	std::sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i)printf("%d ",a[i].i);
	return 0;
}
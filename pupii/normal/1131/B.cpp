#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
#define int long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
il int calc(int a,int b,int A,int B){
	if(a>b)std::swap(a,b);
	if(A>B)std::swap(A,B);
	if(A<b)return 0;
	return A-b+1-(a==b);
}
main(){
	int n=gi(),a=0,b=0,A,B,ans=1;
	while(n--){
		A=gi(),B=gi();
		if(a!=A||b!=B)ans+=calc(a,b,A,B);
		a=A,b=B;
	}
	printf("%lld\n",ans);
	return 0;
}
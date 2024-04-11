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
int a[100010];
int main(){
	int n=gi(),k=gi(),p=1;
	for(int i=1;i<=n<<1;++i)a[i]=i;
	while(k--)std::swap(a[p],a[p+1]),p+=2;
	for(int i=1;i<=n<<1;++i)printf("%d ",a[i]);
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
inline int Min(int p,int q){return p<q?p:q;}
inline int Max(int p,int q){return p>q?p:q;}
int n,k,a[100001],min=2147483647,max=-2147483647;
int m1[100001],m2[100001];
void init(){
	scanf("%d%d",&n,&k);
	F(i,1,n) scanf("%d",a+i), max=Max(max,a[i]), min=Min(min,a[i]);
}
int main(){
	init();
	if(k>=3) printf("%d",max);
	else if(k==1) printf("%d",min);
	else{
		m1[1]=a[1]; F(i,2,n) m1[i]=Min(m1[i-1],a[i]);
		m2[n]=a[n]; dF(i,n-1,1) m2[i]=Min(m2[i+1],a[i]);
		int Ans=-2147483647;
		F(i,2,n) Ans=Max(Ans,Max(m1[i-1],m2[i]));
		printf("%d",Ans);
	}
	return 0;
}
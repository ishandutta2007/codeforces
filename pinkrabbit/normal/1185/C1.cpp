#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 200005
#define ll long long
#define mod 998244353
int n,m,q,k;
int a[MN],b[105];
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n){
		int t=m-a[i],s=0;
		F(j,1,100){
			if(t>=b[j]*j)t-=b[j]*j,s+=b[j];
			else{s+=t/j;break;}
		}printf("%d ",i-1-s);
		++b[a[i]];
	}
	return 0;
}
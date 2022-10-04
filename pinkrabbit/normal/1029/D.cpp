#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;
#define Luogu Gugugu
int n,k;
int a[200001],l[200001];
map<int,int> mp[11];
LL Ans;

int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n) scanf("%d",a+i);
	F(i,1,n){
		int x=a[i];
		while(x) ++l[i], x/=10;
	}
	int X=1;
	F(j,1,10){
		X=X*10ll%k;
		F(i,1,n) ++mp[j][(LL)a[i]*X%k];
	}
	F(i,1,n) Ans+=mp[l[i]][(k-(a[i]%k))%k];
	F(i,1,n){
		X=1;
		F(j,1,l[i]) X=X*10ll%k;
		if((a[i]+(LL)X*a[i])%k==0) --Ans;
	}
	printf("%I64d",Ans);
	return 0;
}
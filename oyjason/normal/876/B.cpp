#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 100002
#define mod
using namespace std;
int n,m,k,a[M],b[M],p[M];
bool space=false;
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]%m;
		p[b[i]]++;
		if(p[b[i]]==k){
			printf("Yes\n");
			for(int j=1;j<=i;j++){
				if(b[j]!=b[i]) continue;
				if(space) printf(" ");
				space=true;
				printf("%d",a[j]);
			}
			return 0;
		}
	}
	printf("No");
	return 0;
}
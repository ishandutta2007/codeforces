#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int A[N],B[N],C[N];
int main(){
	int n,K,i;
	scanf("%d%d",&n,&K);
	for (i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	for (i=1;i<=n;i++){
		scanf("%d",&B[i]);
	}
	A[K]+=B[1];
	int Ans=1,h=0;
	for (i=1;i<=n;i++){
		if (i==K){
			continue;
		}
		if (A[i]+B[n]>A[K]){
			Ans++;
		}else{
			C[++h]=A[i];
		}
	}
	for (i=1;i<=h;i++){
		if (C[i]+B[n-i+1]>A[K]){
			Ans++;
		}
	}
	printf("%d\n",Ans);
	return 0;
}
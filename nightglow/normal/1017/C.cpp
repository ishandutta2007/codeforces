#include<bits/stdc++.h>
using namespace std;int n;
int main(){
	scanf("%d",&n);
	int ans=1e9,K;
	for (int k=1;k<=n;k++){
		int now=n/k+(n%k>0)+k;
		if (now<ans)
			ans=now,K=k;
	}
	int k=K;
	for (int i=0;i<n;i+=k)
		if (i+k<=n){
			for (int j=0;j<k;j++)
				printf("%d ",i+k-j);
		}
		else {
			for (int j=n;i<n;i++,j--)
				printf("%d ",j);
			break;	
		}
}
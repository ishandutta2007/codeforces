#include<stdio.h>
int main(){
	int t=0;
	 scanf("%d",&t);
	 while(t--){
	 	int size=0;
	 	long long int sum=0;
	 	scanf("%d",&size);
	 	long long int arr[size];
	 	for(int i=1;i<=size;i++){
	 		scanf("%lld",&arr[i]);
	 	}

	    arr[0] = -arr[1];
	    
 		int j=0;
 		int k=1;
 		while(k<=size){
 			if(arr[k]*arr[j]<0){
 				if(k<=size-1){
 					int p=k+1;
 					while(arr[p]*arr[k]>0 && p<=size){
 						if(arr[p]>=arr[k]){
 							k=p;
 						}
 						p++;
 					}
 				}
 				

 				sum=sum+arr[k];
 				j=k;
 			}
 			k++;
 		}
	 	printf("%lld\n",sum);

	 }
}
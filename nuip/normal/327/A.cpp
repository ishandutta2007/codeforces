#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<cmath>

using namespace std;

int main(){

	int num,N,cnt=0,maxv=-1000,ones=0,i,j,a[105];
	cin>>N;
	for(i=0;i<N;i++){
		scanf("%d",a+i);
		ones+=(a[i]==1);
	}
		
	for(i=0;i<N;i++){
		int sum=0;
		for(j=i;j<N;j++){
			sum+=(a[j]==0);
			sum-=(a[j]==1);
			if(sum>maxv)maxv=sum;
		}
//	cout<<ones<<","<<maxv<<endl;
	}
	
	cout<<ones+maxv<<endl;

	return 0;
}
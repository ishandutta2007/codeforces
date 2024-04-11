#include  <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200000;
int a[2][N],b[2][N];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[0][i],&a[1][i]);
	}
	
	int m;scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&b[0][i],&b[1][i]);
	}
	
	printf("%d\n",max(0,max(*max_element(a[0],a[0]+n)-*min_element(b[1],b[1]+m),*max_element(b[0],b[0]+m)-*min_element(a[1],a[1]+n))));
}
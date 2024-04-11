#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;;i++)
	if ((1<<i)-1>=n){
		printf("%d\n",i);
		return 0;
	}
}
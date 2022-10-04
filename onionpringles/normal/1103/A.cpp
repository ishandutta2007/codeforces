#include <bits/stdc++.h>
using namespace std;
char b[1010];
int main(){
	scanf("%s",b);
	int n=strlen(b);
	int A=0,B=0;
	for(int i=0;i<n;i++){
		if(b[i]=='0'){
			if(A%2==0)puts("1 1");
			else puts("3 1");
			A++;
		}
		else{
			printf("%d 3\n",B%4+1);
			B++;
		}
	}
}
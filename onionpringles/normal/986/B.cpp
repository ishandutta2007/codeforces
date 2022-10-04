#include <bits/stdc++.h>
using namespace std;
int a[1010101],chk[1010101];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int c=n&1;
	for(int i=1;i<=n;i++){
		if(chk[i])continue;
		chk[i]=1;
		int len=0;
		for(int j=a[i];j!=i;j=a[j]){
			chk[j]=1;len++;
		}
		c^=len&1;
	}
	if(c==0)puts("Petr");
	else puts("Um_nik");
}
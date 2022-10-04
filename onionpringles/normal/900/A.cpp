#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;scanf("%d",&n);
	int a=0,b=0;
	for(int i=0;i<n;i++){
		int x;scanf("%d%*d",&x);
		if(x<0)a++;
		else b++;
	}
	if(a>1&&b>1)puts("No");
	else puts("Yes");
}
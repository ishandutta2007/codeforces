#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	int cl = 0,cr = 0;
	int sk;
	for(int j = 0;j<n;j++){
		scanf("%i",&sk);
		if(sk==-1)
			cl++;
		else
			cr++;
	}
	int li,ri;
	for(int j = 0;j<m;j++){
		scanf("%i %i",&li,&ri);
		if((ri-li+1)%2==1)
			printf("0\n");
		else{
			if(cr>=(ri-li+1)/2&&cl>=(ri-li+1)/2)
				printf("1\n");
			else
				printf("0\n");
		}
	}
	return 0;
}
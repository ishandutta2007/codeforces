#include <bits/stdc++.h>
using namespace std;
char b[1010];
int main(){
	while(1){
		scanf("%s",b);
		if(b[0]=='e')break;
		puts("? 0 1");
		fflush(stdout);
		scanf("%s",b);
		if(b[0]=='x'){
			puts("! 1");
			fflush(stdout);continue;
		}
		int i=0;
		while(1){
			printf("? %d %d\n",1<<i,1<<i+1);
			fflush(stdout);
			scanf("%s",b);
			if(b[0]=='x')break;
			else i++;
		}
		int low=(1<<i)+1,high=1<<i+1;
		while(low!=high){
			int mid=(low+high)/2;
			printf("? %d %d\n",1<<i,mid);
			fflush(stdout);
			scanf("%s",b);
			if(b[0]=='x')high=mid;
			else low=mid+1;
		}
		printf("! %d\n",low);fflush(stdout);
	}
}
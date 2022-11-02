#include<bits/stdc++.h>
using namespace std;
char s[4],t[4];
int res;
int main(){
	scanf("%s%s",s,t);
	res=max(abs(s[0]-t[0]),abs(s[1]-t[1]));
	printf("%d\n",res);
	for (int i=0;i<res;i++){
		if (s[0]>t[0]) printf("L"),s[0]--;
		else if (s[0]<t[0]) printf("R"),s[0]++;
		if (s[1]>t[1]) printf("D"),s[1]--;
		else if (s[1]<t[1]) printf("U"),s[1]++;
		printf("\n");
	}
}
#include <bits/stdc++.h>
int n,flag1,flag2;
char s1[100],s2[100];
int main() {
	scanf("%s",s1+1);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		scanf("%s",s2+1);
		if (s2[1]==s1[2]) flag1=1;
		if (s2[2]==s1[1]) flag2=1;
		if (s2[1]==s1[1]&&s2[2]==s1[2]) {printf("YES");return 0;}
	}if (flag1&&flag2) printf("YES");
	else printf("NO");
	return 0;
}
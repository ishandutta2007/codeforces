#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int main(){
	scanf("%*d%*d");
	char s1[21], s2[21];
	scanf("%s%s", s1, s2);
	char s3[] = { s1[0], s1[strlen(s1) - 1], s2[0], s2[strlen(s2) - 1], 0 };
	if (strcmp(s3, "<>v^") == 0 || strcmp(s3, "><^v") == 0)printf("YES\n");
	else printf("NO\n");
	return 0;
}
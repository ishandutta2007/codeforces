#include <bits/stdc++.h>
using namespace std;
char b[10101];
void bad(){
	puts("NO");exit(0);
}
int main(){
	scanf("%s",b);
	int n=strlen(b);
	int j;
	for(j=0;j<n;j++)if(b[j]=='h')break;
	if(j==n)bad();
	for(;j<n;j++)if(b[j]=='e')break;
	if(j==n)bad();
	for(;j<n;j++)if(b[j]=='i')break;
	if(j==n)bad();
	for(;j<n;j++)if(b[j]=='d')break;
	if(j==n)bad();
	for(;j<n;j++)if(b[j]=='i')break;
	if(j==n)bad();
	puts("YES");
}
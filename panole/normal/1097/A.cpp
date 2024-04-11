#include<bits/stdc++.h>
using namespace std;

char s[6][5]; 

int main()
{
	for (int i=0; i<6; i++)scanf("%s",s[i]);
	for (int i=1; i<6; i++)
		if (s[i][0]==s[0][0]||s[i][1]==s[0][1]) {puts("YES"); return 0;}
	puts("NO");
	return 0;
}
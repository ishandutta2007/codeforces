#include<bits/stdc++.h>

using namespace std;

#define N 100

int n,ans;
char s[N];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n;i++)
		if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'|| s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' || s[i]=='9') ans++;
	printf("%d\n",ans);
	
	return 0;
}
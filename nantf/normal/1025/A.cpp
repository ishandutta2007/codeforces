#include<bits/stdc++.h>
using namespace std;
int n,cnt[26];
char str[100010];
int main(){
	scanf("%d%s",&n,str+1);
	for(int i=1;i<=n;i++) cnt[str[i]-'a']++;
	for(int i=0;i<26;i++)
		if(cnt[i]>=2) return printf("Yes\n"),0;
	printf(n==1?"Yes\n":"No\n");
}
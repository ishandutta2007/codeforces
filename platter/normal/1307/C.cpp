#include <bits/stdc++.h>
using namespace std;

long long cnt[26];
long long two[26][26];

int main(void) {
	char str[100055];
	scanf("%s",str);
	int n=strlen(str);
	long long ret=0;
	for(int i=0;i<n;i++) {
		cnt[str[i]-'a']++;
		ret=max(ret,cnt[str[i]-'a']);
	}
	for(int i=0;i<n;i++) {
		int pos=str[i]-'a';
		cnt[pos]--;
		for(int j=0;j<26;j++) {
			two[pos][j]+=cnt[j];
		}
	}
	for(int i=0;i<26;i++) {
		for(int j=0;j<26;j++) {
			ret=max(ret,two[i][j]);
		}
	}
	printf("%lld",ret);
}
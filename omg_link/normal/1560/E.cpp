#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 500000

using std::reverse;

int n,cc;
int cnt[26];
char s[MN+5],t[MN+5],ansp[30];

bool check(){
	static bool skip[MN+5];
	int pos = 0;
	for(int i=1;t[i];i++)
		skip[i] = false;
	for(int i=1;i<=cc;i++){
		for(int j=1;t[j];j++){
			if(skip[j]) continue;
			if(s[++pos]!=t[j]) return false;
			if(t[j]==ansp[i]) skip[j] = true;
		}
	}
	return true;
}

void solve(){
	memset(cnt,0,sizeof(cnt));
	scanf("%s",&s[1]);
	n = strlen(&s[1]);
	cc = 0;
	for(int i=n;i>=1;i--){
		if(!cnt[s[i]-'a'])
			ansp[++cc] = s[i];
		cnt[s[i]-'a']++;
	}
	ansp[cc+1] = '\0';
	reverse(ansp+1,ansp+1+cc);
	int sum = 0;
	for(int i=1;i<=cc;i++){
		if(cnt[ansp[i]-'a']%i){
			puts("-1");
			return;
		}else{
			cnt[ansp[i]-'a'] /= i;
			sum += cnt[ansp[i]-'a'];
		}
	}
	for(int i=1;i<=sum;i++){
		t[i] = s[i];
		cnt[t[i]-'a']--;
	}
	t[sum+1] = '\0';
	for(int i=0;i<26;i++)
		if(cnt[i]){
			puts("-1");
			return;
		}
	if(!check()){
		puts("-1");
		return;
	}
	printf("%s %s\n",&t[1],&ansp[1]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}
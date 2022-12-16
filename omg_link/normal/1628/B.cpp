#include <stdio.h>
#include <string.h>
#include <set>
#define MN 100000

using std::set;

struct Word{
	char s[4];
}w[MN+5];

int cnt2[26][26],cnt3[26][26][26];

bool isPalindrome(const char* s){
	int l = strlen(s);
	for(int i=0;i<l/2;i++)
		if(s[i]!=s[l-i-1]) return false;
	return true;
}

bool solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",&w[i].s[0]);
	}
	memset(cnt2,0,sizeof(cnt2));
	memset(cnt3,0,sizeof(cnt3));
	for(int i=1;i<=n;i++){
		if(isPalindrome(&w[i].s[0])){
			return true;
		}
		int len = strlen(&w[i].s[0]);
		if(len==2){
			int c1 = w[i].s[0]-'a';
			int c2 = w[i].s[1]-'a';
			if(cnt2[c2][c1]) return true;
			for(int c3=0;c3<26;c3++){
				if(cnt3[c2][c1][c3]) return true;
			}
			cnt2[c1][c2]++;
		}else{
			int c1 = w[i].s[0]-'a';
			int c2 = w[i].s[1]-'a';
			int c3 = w[i].s[2]-'a';
			if(cnt2[c3][c2]) return true;
			if(cnt3[c3][c2][c1]) return true;
			cnt3[c1][c2][c3]++;
		}
	}
	return false;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		puts(solve()?"YES":"NO");
	}
}
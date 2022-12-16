#include <stdio.h>
#include <string.h>
#include <set>
#define MN 1000

using std::set;

int n;
char s[MN+5];

struct Word{
	char c[6];
	Word(){
		memset(c,0,sizeof(c));
	}
	Word(int l,int r){
		int len = r-l+1;
		for(int i=0;i<len;i++)
			c[i] = s[l+i];
		c[len] = '\0';
	}
	bool operator < (const Word& that)const{
		for(int i=0;i<6;i++){
			if(c[i]!=that.c[i])
				return c[i] < that.c[i];
			if(c[i]=='\0') return false;
		}
		return false;
	}
};

set<Word> S;

bool findAns(Word wd,int w,int len){
	if(w==len){
		wd.c[len] = '\0';
		if(S.find(wd)==S.end()){
			puts(wd.c);
			return true;
		}else{
			return false;
		}
	}
	for(char c='a';c<='z';c++){
		wd.c[w] = c;
		if(findAns(wd,w+1,len)) return true;
	}
	return false;
}

void solve(){
	scanf("%d%s",&n,&s[1]);
	for(int l=1,sz=26;l<=5;l++,sz*=26){
		S.clear();
		for(int i=1;i+l-1<=n;i++){
			S.insert(Word(i,i+l-1));
		}
		if(S.size()!=sz){
			findAns(Word(),0,l);
			break;
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}
#include <stdio.h>
#include <algorithm>
#define MN 100000

using std::min;

struct S_t{
	int l,r,c;
}s[MN+5];

int f[MN+5][2];
int ans[MN+5];

bool isBetterL(S_t s1,S_t s2){
	if(s1.l!=s2.l)
		return s1.l < s2.l;
	else
		return s1.c < s2.c;
}

bool isBetterR(S_t s1,S_t s2){
	if(s1.r!=s2.r)
		return s1.r > s2.r;
	else
		return s1.c < s2.c;
}

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&s[i].l,&s[i].r,&s[i].c);
	}
	f[1][0] = f[1][1] = 1;
	for(int i=2;i<=n;i++){
		if(isBetterL(s[i],s[f[i-1][0]])){
			f[i][0] = i;
		}else{
			f[i][0] = f[i-1][0];
		}
		if(isBetterR(s[i],s[f[i-1][1]])){
			f[i][1] = i;
		}else{
			f[i][1] = f[i-1][1];
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i][0]==f[i][1]){
			ans[i] = s[f[i][0]].c;
		}else{
			ans[i] = s[f[i][0]].c+s[f[i][1]].c;
		}
	}
	int bid = 1;
	for(int i=1;i<=n;i++){
		if(s[i].l<=s[bid].l&&s[i].r>=s[bid].r){
			if(s[i].l<s[bid].l||s[i].r>s[bid].r)
				bid = i;
			else if(s[i].c<s[bid].c)
				bid = i;
		}
		if(s[bid].l==s[f[i][0]].l&&s[bid].r==s[f[i][1]].r){
			ans[i] = min(ans[i],s[bid].c);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}
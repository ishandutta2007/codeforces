#include <stdio.h>
#include <algorithm>
#define MN 200000

using std::min;

const char* t[6] = {
	"abc","acb","bac","bca","cab","cba"
};

char s[MN+5];
int ans[6][MN+5];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",&s[1]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<6;j++)
			ans[j][i] = ans[j][i-1]+(s[i]!=t[j][i%3]);
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		int cans = 0x7fffffff;
		for(int j=0;j<6;j++)
			cans = min(cans,ans[j][r]-ans[j][l-1]);
		printf("%d\n",cans);
	}
}
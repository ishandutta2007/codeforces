#include <stdio.h>

int n;

int table[12][3]={
	{0,0,0},
	{-1,-1,-1},
	{-1,-1,-1},
	{1,0,0},
	{-1,-1,-1},
	{0,1,0},
	{2,0,0},
	{0,0,1},
	{1,1,0},
	{3,0,0},
	{0,2,0},
	{2,1,0}
};

void solve(){
	scanf("%d",&n);
	if(n<=11){
		if(table[n][0]!=-1)
			printf("%d %d %d\n",table[n][0],table[n][1],table[n][2]);
		else
			printf("%d\n",-1);
	}else{
		int ans[3] = {0};
		while(n>11){
			n -= 7;
			ans[2]++;
		}
		ans[0] += table[n][0];
		ans[1] += table[n][1];
		ans[2] += table[n][2];
		printf("%d %d %d\n",ans[0],ans[1],ans[2]);
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}
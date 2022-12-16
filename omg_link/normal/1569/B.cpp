#include <stdio.h>
#include <string.h>
#include <vector>
#define MN 50

using std::vector;

char ans[MN+5][MN+5];

void solve(){
	int n;
	vector<int> v1,v2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%1d",&a);
		if(a==1)
			v1.push_back(i);
		else
			v2.push_back(i);
	}
	if(v2.size()==1||v2.size()==2){
		puts("NO");
		return;
	}
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans[i][j] = '=';
	int m = v2.size();
	for(int i=0;i<m;i++){
		ans[v2[i]][v2[(i+1)%m]] = '+';
		ans[v2[(i+1)%m]][v2[i]] = '-';
	}
	for(int i=1;i<=n;i++)
		ans[i][i] = 'X';
	puts("YES");
	for(int i=1;i<=n;i++)
		puts(&ans[i][1]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}
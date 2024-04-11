#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	char s[1000005];
	cin>>n>>m>>k;
	scanf("%s",s+1);
	vector<char> ans[1005];
	sort(s+1,s+n*m+1);
	int q=0,l=1;
	for(int i=1;i<=m;i++){
		for(int j=l;j<=k;j++)ans[j].push_back(s[++q]);
		l=k;
		while(l>1&&ans[l-1].size()==i&&ans[l-1][i-1]==ans[k][i-1])l--;
	}
	for(int i=1;i<=n;i++){
		while(ans[i].size()<m){
			ans[i].push_back(s[++q]);
		} 
		for(int j=0;j<m;j++)putchar(ans[i][j]);
		putchar('\n');
	}
	return 0;
}
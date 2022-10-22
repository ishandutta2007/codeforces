#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
vector<int> v[300005];
int a[300005],n,k;
int dfs(int p){
	if(v[p].size()==0)return 1;
	if(a[p]){
		int re=1000000000;
		for(int i=0;i<v[p].size();i++)re=min(re,dfs(v[p][i]));
		return re;
	}else{
		int re=0;
		for(int i=0;i<v[p].size();i++)re+=dfs(v[p][i]);
		return re;
	}
}
int main(){
	scanf("%d",&n);
	int t;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		scanf("%d",&t);
		v[t].push_back(i);
	}
	for(int i=1;i<=n;i++)if(!v[i].size())k++;
	printf("%d",k-dfs(1)+1);
	return 0;
}
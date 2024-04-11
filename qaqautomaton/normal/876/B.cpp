#include<bits/stdc++.h>
using namespace std;
int a[102424];
vector<int> s[102424];
int main(){
	int n,m,k,x;
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		++a[x%m];	
		s[x%m].push_back(x);
	}
	for(int i=0;i<m;++i)if(a[i]>=k){
		printf("Yes\n");
		for(int j=0;j<k;++j)printf("%d%c",s[i][j],j==k-1?'\n':' ');
		return 0;
	}
	printf("No\n");
	return 0;
}
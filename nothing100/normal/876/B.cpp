#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,m;
vector<int> b[100010];
int main() {
	scanf("%d%d%d",&n,&k,&m);
	int o;
	for (int i=0;i<n;i++){
		scanf("%d",&o);
		b[o%m].push_back(o);
	}
	for (int i=0;i<m;i++)
	if (b[i].size()>=k){
		printf("Yes\n");
		for (int j=0;j<k;j++) printf("%d ",b[i][j]);
		return 0;
	}
	printf("No\n");
}
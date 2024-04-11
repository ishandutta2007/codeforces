#include <stdio.h>
#include <algorithm>
#include <vector>
#define MN 100

int n,a[MN+5],b[MN+5];
std::vector<int> c;

void solve(){
	c.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		if(b[i]==0) c.push_back(a[i]);
	std::sort(c.begin(),c.end(),std::greater<int>());
	for(int i=1,j=0;i<=n;i++){
		if(b[i]) continue;
		a[i] = c[j++];
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}
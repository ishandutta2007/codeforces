#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int f[3000005],n,a[400005];
int vis[3000005],l[3000005]; 
int main(){
	for(int i=2;i<=3000000;i++)vis[i]=1;
	for(int i=2;i<=3000000;i++){
		if(vis[i]==1){
			for(int j=(i<<1);j<=3000000;j+=i){
				if(vis[j]==1)vis[j]=i;
			}
		}
	}
	int p=0;
	for(int i=2;i<=3000000;i++){
		if(vis[i]==1)l[i]=++p;
	}
	scanf("%d",&n);
	for(int i=1;i<=(n<<1);i++)scanf("%d",&a[i]),f[a[i]]++;
	sort(a+1,a+(n<<1)+1,greater<int>());
	vector <int> ans;
	ans.clear();
	for(int i=1;i<=(n<<1);i++){
		if(!f[a[i]])continue;
		f[a[i]]--;
		if(vis[a[i]]==1){
			f[l[a[i]]]--;
			ans.push_back(l[a[i]]);
		}else {
			ans.push_back(a[i]);
			f[a[i]/vis[a[i]]]--;
		}
	}
	for(int i=0;i<n;i++)printf("%d ",ans[i]);
	return 0;
}
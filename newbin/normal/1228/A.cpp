#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int l,r,ans;
int vis[10];
bool check(int x){
	memset(vis,0,sizeof vis);
	while(x){
		int tmp=x%10;
		if(vis[tmp]) return 0;
		vis[tmp]++;
		x/=10;
	}
	return 1;
}
int main(){
	scanf("%d%d",&l,&r);
	for(int i=l; i<=r; ++i){
		if(check(i)){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}
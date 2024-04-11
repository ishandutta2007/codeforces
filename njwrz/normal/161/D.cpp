#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n,k;
vector<int> a[50005];
ll t,f[50005][505],ans;
void dfs(int p,int la){
    f[p][0]=1;
    for(int i=0;i<a[p].size();i++){
    	if(a[p][i]!=la){
			dfs(a[p][i],p);
			for(int j=1;j<=k;j++){
				f[p][j]+=f[a[p][i]][j-1];	
			}
		}
	}
    ans=ans+f[p][k];t=0;
    for(int i=0;i<a[p].size();i++){
    	if(a[p][i]!=la){
    		for(int j=1;j<k;j++){
    			t=t+f[a[p][i]][j-1]*(f[p][k-j]-f[a[p][i]][k-j-1]);
			}
		}
	}
	ans=ans+(t>>1);
}
int main(){
	int x,y;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
    	scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
    dfs(1,0);
    printf("%lld",ans);
}
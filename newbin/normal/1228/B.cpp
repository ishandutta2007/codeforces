#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
const int mod=1e9+7;
int mp[maxn][maxn];
int h,w,r[maxn],c[maxn];
int main(){
	scanf("%d%d",&h,&w);
	int cnt=h*w;
	memset(mp,-1,sizeof mp);
	for(int i=0; i<h; ++i){
		scanf("%d",&r[i]);
		int j;
		for(j=0; j<r[i]&j<w; ++j) mp[i][j]=1,cnt--;
		if(j<w){
			mp[i][j]=0;
			cnt--;
		}
	}
	
	for(int i=0; i<w; ++i){
		scanf("%d",&c[i]);
		int j;
		for(j=0; j<c[i]&&j<h; ++j){
			if(mp[j][i]==0){
				cout<<0<<endl;
				return 0;
			}
			if(mp[j][i]==-1) cnt--;
			mp[j][i]=1;
		}
		if(j<h&&mp[j][i]==-1){
			cnt--;
			mp[j][i]=0;
		}
		if(j<h&&mp[j][i]==1){
			cout<<0<<endl;
			return 0;
		}
	}
	
	int ans=1;
	for(int i=1; i<=cnt; ++i) ans=ans*2%mod;
	cout<<ans<<endl;
	
}
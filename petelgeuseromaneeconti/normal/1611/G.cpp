#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T,n,m;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		vector<string>s(n);
		rep(i,0,n-1)cin>>s[i];
		vector<vector<int> >dp1(n,vector<int>(m,0));
		auto dp2(dp1);
		per(j,m-1,0){
			rep(i,0,n-1){
				if(s[i][j]=='1'){
					if(j+2<m){
						dp1[i][j]=max(dp1[i][j],dp2[i][j+2]+1);
					}else{
						dp1[i][j]=max(dp1[i][j],1);
					}
				}
				dp2[i][j]=dp1[i][j];
				if(i-1>=0&&j+1<m){
					dp2[i][j]=max(dp2[i][j],dp2[i-1][j+1]);
				}
				if(i+1<n&&j+1<m){
					dp2[i][j]=max(dp2[i][j],dp2[i+1][j+1]);
				}
			}
		}
		if(n==1){
			int ans=0;
			rep(i,0,m-1)ans+=s[0][i]=='1';
			printf("%d\n",ans);
			continue;
		}
		int f[2]={0,0};
		rep(i,0,n-1){
			f[i&1]=max(f[i&1],dp2[i][0]);
		}
		printf("%d\n",f[0]+f[1]);
	}
	return 0;
}
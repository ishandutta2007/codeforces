#include<iostream>
using namespace std;
int n,a[1001][1001],dp1[1001][1001],dp2[1001][1001];
int fj(int x,int y){
	int t=0;
	while(x%y==0){
		x/=y;t++;
	}
	return t;
}
int INF=2000000000;
int main(){
	cin>>n;
	int i,j,f=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				dp2[i][j]=INF;dp1[i][j]=INF;f=1;
			}
		}
	}
	if(dp1[1][1]==0)dp1[1][1]=fj(a[1][1],2);
	for(i=2;i<=n;i++){
		if(dp1[1][i]==0)dp1[1][i]=dp1[1][i-1]+fj(a[1][i],2);
		if(dp1[i][1]==0)dp1[i][1]=dp1[i-1][1]+fj(a[i][1],2);
	}
	for(i=2;i<=n;i++){
		for(j=2;j<=n;j++){
			if(dp1[i][j]==0){
				dp1[i][j]=min(dp1[i-1][j],dp1[i][j-1])+fj(a[i][j],2);
			}
		}
	}
	if(dp2[1][1]==0)dp2[1][1]=fj(a[1][1],5);
	for(i=2;i<=n;i++){
		if(dp2[1][i]==0)dp2[1][i]=dp2[1][i-1]+fj(a[1][i],5);
		if(dp2[i][1]==0)dp2[i][1]=dp2[i-1][1]+fj(a[i][1],5);
	}
	for(i=2;i<=n;i++){
		for(j=2;j<=n;j++){
			if(dp2[i][j]==0){
				dp2[i][j]=min(dp2[i-1][j],dp2[i][j-1])+fj(a[i][j],5);
			}
		}
	}
	int ans=min(dp1[n][n],dp2[n][n]);
	if(f)ans=min(ans,1);
	cout<<ans<<endl;
	if(ans==dp1[n][n]){
		i=n;j=n;string s="";
		for(int k=1;k<n*2-1;k++){
			if(i>1&&dp1[i-1][j]+fj(a[i][j],2)==dp1[i][j]){
				s="D"+s;i--;
			}else s="R"+s,j--;
		}
		cout<<s;
	}else if(ans==dp2[n][n]){	
		i=n;j=n;string s="";
		for(int k=1;k<n*2-1;k++){
			if(i>1&&dp2[i-1][j]+fj(a[i][j],5)==dp2[i][j]){
				s="D"+s;i--;
			}else s="R"+s,j--;
		}
		cout<<s;
	}else{
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(a[i][j]==0){
					int k;
					for(k=0;k<i-1;k++)cout<<"D";
					for(k=1;k<n;k++)cout<<"R";
					for(k=0;k<n-i;k++)cout<<"D";
					return 0; 
				}
			}
		}
	}
	return 0;
}
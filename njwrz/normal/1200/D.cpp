#include <bits/stdc++.h>
using namespace std;
char a[2005][2005];
int c[2005][2005],bx;
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(int i=0;i<n;i++){
		int mini=100000,maxi=-10;
		for(int j=0;j<n;j++){
			if(a[i][j]=='B'){
				maxi=max(maxi,j);
				mini=min(mini,j);
			}
		}
		if(mini==100000){
			bx++;continue;
		}
		if(maxi-mini+1>k)continue;
		int l,x;
		l=maxi-k+1;
		l=max(0,l);
		x=i-k+1;
		x=max(x,0);
		for(int j=x;j<=i;j++){
			c[j][l]++;
			c[j][mini+1]--;
		}
	}
	for(int j=0;j<n;j++){
		int mini=100000,maxi=-10;
		for(int i=0;i<n;i++){
			if(a[i][j]=='B'){
				maxi=max(maxi,i);
				mini=min(mini,i);
			}
		}
		if(mini==100000){
			bx++;continue;
		}
		if(maxi-mini+1>k)continue;
		int l,x;
		l=maxi-k+1;
		l=max(0,l);
		x=j-k+1;
		x=max(0,x);
		for(int i=l;i<=mini;i++){
			c[i][x]++;
			c[i][j+1]--;
		}
	}
	int ans=0;
	for(int i=0;i<n-k+1;i++){
		int t=0;
		for(int j=0;j<n-k+1;j++){
			t+=c[i][j];ans=max(ans,t);
		}
	}
	cout<<ans+bx;
	return 0;
}
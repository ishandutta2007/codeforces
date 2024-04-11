#include <bits/stdc++.h>
using namespace std;
int p[27][27],a[100005];
int main(){
	int k,n;
	cin>>n>>k;
	char x;
	if(k>n/2)k=n+1-k;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=x-'a'+1;
	}
	for(int i=1;i<=26;i++){
		for(int j=1;j<=26;j++){
			p[i][j]=min(abs(i-j),i+26-j);
			p[i][j]=min(p[i][j],j+26-i);
		}
	}
	int ans=0,l=1000001,r=-10;
	for(int i=1;i<=n/2;i++){
		ans+=p[a[i]][a[n-i+1]];
		if(a[i]!=a[n-i+1]){
			l=min(l,i);r=max(r,i);
		}
	}
	if(r!=-10){
		ans+=min(abs(k-l),abs(k-r))+r-l;
	}
	cout<<max(0,ans);
	return 0;
}
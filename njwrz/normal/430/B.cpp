#include <bits/stdc++.h>
using namespace std;
int a[105],s[105],l[105],n,cnt,m,x;
int main(){
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)cin>>a[i];
	int t=1,last=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])t++;
		else{
			s[++cnt]=last;
			l[cnt]=t;
			last=a[i];t=1;
		}
	}
	s[++cnt]=last;
	l[cnt]=t;
	int maxi=0;
	for(int i=1;i<=cnt;i++){
		if(s[i]==x&&l[i]>1){
			int ans=l[i],z=i-1,y=i+1;
			while(s[z]==s[y]&&l[z]+l[y]>2){
				ans+=l[z]+l[y];z--;y++;
			}
			maxi=max(maxi,ans);
		}
	}
	cout<<maxi;
	return 0;
}
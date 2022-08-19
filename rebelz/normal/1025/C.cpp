#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

char s[100005];
int n;
int cnt[100005],x[100005];

int main(){
	cin>>(s+1);
	n=strlen(s+1);
	for(int i=n;i>=1;i--){
		if(s[i]!=s[i+1])
			cnt[i]=cnt[i+1]+1;
		else
			break;
	}
	for(int i=n;i>=1;i--)
		if(cnt[i]==0)
			cnt[i]=cnt[i+1];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]!=s[i-1])
			x[i]=x[i-1]+1;
		else{
			ans=max(ans,x[i-1]);
			x[i]=1;
		}
	}
	ans=max(ans,x[n]);
	if(s[1]==s[n]){
		cout<<ans<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++)
		if(x[i]==1)
			x[i]=0;
	for(int i=2;i<=n;i++)
		if(x[i-1]==0)
			x[i]=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,x[i]+cnt[i+1]);
	cout<<ans<<endl;
	return 0;
}
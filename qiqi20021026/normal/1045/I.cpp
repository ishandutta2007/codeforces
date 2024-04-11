#include<bits/stdc++.h>
#define N 500005
using namespace std;
map<int,int>mp;
int n,bin[26],has[N];
char s[N*2]; 
int main(){
	scanf("%d",&n);
	bin[0]=1;
	for (int i=1;i<26;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		int m=strlen(s+1);
		for (int j=1;j<=m;j++) has[i]^=bin[s[j]-'a'];
		mp[has[i]]++;
	}
	long long ans;
	for (int i=1;i<=n;i++){
		ans+=1ll*(mp[has[i]]-1);
		for (int j=0;j<26;j++){
			int x=1<<j;
			ans=ans+1ll*mp[has[i]^x];
		}
	}
	printf("%lld\n",ans/2);
	return 0;
}
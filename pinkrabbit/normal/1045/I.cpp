#include<bits/stdc++.h>
using namespace std;
int n,b[26];
char str[1000005];
map<int,int> mp;
long long Ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",str);
		for(int j=0;j<26;++j) b[j]=0;
		for(int j=0;str[j];++j) b[str[j]-'a']^=1;
		int S=0;
		for(int j=0;j<26;++j) S|=b[j]<<j;
		Ans+=mp[S]; ++mp[S];
		for(int j=0;j<26;++j) Ans+=mp[S^1<<j];
	} printf("%lld\n",Ans);
	return 0;
}
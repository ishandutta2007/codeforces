#include<bits/stdc++.h>
using namespace std;
int n;
char str[1005][1005];
int mp[26][26];
int d[26],v[26];
char Ans[29],t;
int main(){
//	freopen("sort.in","r",stdin);
//	freopen("sort.out","w",stdout);
	scanf("%d",&n);
	if(n==0) return puts("abcdefghijklmnopqrstuvwxyz"),0;
	if(n==1) return puts("abcdefghijklmnopqrstuvwxyz"),0;
	for(int i=1;i<=n;++i) scanf("%s",str[i]+1);
	for(int i=2;i<=n;++i){
		int k=1;
		while(str[i-1][k]==str[i][k]) ++k;
		// k: lcp + 1
		if(str[i-1][k]!=0&&str[i][k]!=0) mp[str[i-1][k]-'a'][str[i][k]-'a']=1;
		if(str[i][k]==0) return puts("Impossible"),0;
	}
	for(int i=0;i<26;++i) for(int j=0;j<26;++j) if(mp[i][j]) ++d[j];
	for(int i=0;i<26;++i){
		int k=0, j=-1;
		for(;k<26;++k) if(!v[k]&&!d[k]) {j=k; break;}
		if(j==-1) return puts("Impossible"),0;
		v[j]=1;
		Ans[t++]=j+'a';
		for(int k=0;k<26;++k) if(mp[j][k]) --d[k];
	} printf("%s\n",Ans);
	return 0;
}
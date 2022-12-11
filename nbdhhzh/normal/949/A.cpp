#include<bits/stdc++.h>
#define N 400010
using namespace std;
char s[N];
int n,i,p[N],flag,cnt,m,ne[N],use[N],ans,j;
vector<int>vec[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	if(s[i]=='1'){
		ne[p[++cnt]]=i;
		if(cnt>m)flag=1;
	}
	else p[++m]=i;
	m=cnt=0;
	for(i=n;i>=1;i--)
	if(s[i]=='1'){
		ne[i]=p[++cnt];
		if(cnt>m)flag=1;
	}
	else p[++m]=i;
	if(flag){
		puts("-1");
		return 0;
	} 
	for(i=1;i<=n;i++)
	if(!use[i]){
		ans++;
		for(j=i;j;j=ne[j] )
			vec[ans].push_back(j),use[j]=1;
	}
	printf("%d\n",ans);
	for(i=1;i<=ans;i++){
		printf("%d ",vec[i].size());
		for(j=0;j<vec[i].size();j++)
			printf("%d ",vec[i][j]);
		puts("");
	}
}
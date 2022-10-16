#include<iostream>  //
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
int ans=0,cnt=0;
char pre,str[55];
int main(){
	scanf("%d%d%s",&n,&k,str+1);
	sort(str+1,str+n+1);
	pre=str[1];cnt=1;ans=str[1]-'a'+1;
	for(int i=2;i<=n;i++){
	    if(cnt==k) break;
		if(str[i]-pre<2) continue;
		pre=str[i];cnt++;ans+=str[i]-'a'+1;
	}
	if(cnt<k) printf("-1\n");
	else printf("%d\n",ans);
}
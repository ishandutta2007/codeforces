#include<bits/stdc++.h>
using namespace std;
int t,n;
char ch[44],cch[44];
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		scanf("%s",ch);
		for (int i=0;i<n;i++) cch[i]=ch[i];
		sort(ch,ch+n);
		int ans=0;
		for (int i=0;i<n;i++)
		if (ch[i]!=cch[i]) ans++;
		printf("%d\n",ans);
	}
}
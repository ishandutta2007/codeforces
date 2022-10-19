#include<bits/stdc++.h>

using namespace std;

int n,ans;
char s[1000];

int main(){
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;++i){
		++ans;
		if (i!=n&&s[i]!=s[i+1]) ++i;
	}
	printf("%d\n",ans);
	
	return 0;
}
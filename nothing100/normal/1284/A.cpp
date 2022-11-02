#include<bits/stdc++.h>
using namespace std;
char s[22][11],t[22][11];
int n,m,q;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%s",s[i]);
	for (int i=0;i<m;i++) scanf("%s",t[i]);
	scanf("%d",&q);
	while (q--){
		int o;
		scanf("%d",&o);
		o--;
		printf("%s%s\n",s[o%n],t[o%m]);
	}
}
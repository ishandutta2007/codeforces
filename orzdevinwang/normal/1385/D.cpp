#include<bits/stdc++.h>
using namespace std;
int T,n,a[200009],ans[200009],tot;
char s[200009];
int getans(int len,int *f,int val) {
	if(len == 1) return (f[0] != val);
	int ansa=getans(len/2,f,val+1),ansb=getans(len/2,f+len/2,val+1);
	for(int i = 0; i < len/2; i++) ansb += (f[i] != val);
	for(int i = len/2; i < len; i++) ansa += (f[i] != val);
	return min(ansb,ansa);
}
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%s",&n,s);
		for(int i = 0; i < n; i++) a[i] = s[i] - 'a';
		printf("%d\n",getans(n,a,0));
	}
	return 0;
}
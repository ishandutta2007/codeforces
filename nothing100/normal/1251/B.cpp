#include<bits/stdc++.h>
using namespace std;
int cas,n;
char ch[55][55],a[2],one;
int main(){
	scanf("%d",&cas);
	while (cas--){
		one=a[0]=a[1]=0;
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%s",ch[i]);
		for (int i=0;i<n;i++){
			int l=strlen(ch[i]);
			one+=(l&1);
			for (int j=0;j<l;j++)
				a[ch[i][j]-'0']++;
		}
		printf("%d\n",n-((a[0]&1)+(a[1]&1)>one));
	}
}
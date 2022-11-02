#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,r,c;
char s[410][410],ss[410][410];
bitset<410> e[26][410],ans[410];
int main(){
	scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%s",s[i]);
    scanf("%d%d",&r,&c);
    for (int i=0;i<r;i++) scanf("%s",ss[i]);
    for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	for (int k=0;k<26;k++) e[k][i][j]=(s[i][j]==('a'+k));
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++) ans[i][j]=1;
    for (int i=0;i<r;i++)
	for (int j=0;j<c;j++)
	if (ss[i][j]!='?'){
		for (int k=0;k<n;k++)
        ans[k]=ans[k]&((e[ss[i][j]-'a'][(k+i)%n]>>(j%m))|(e[ss[i][j]-'a'][(k+i)%n]<<(m-j%m)));
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++) cout<<ans[i][j];
		printf("\n");
	}
}
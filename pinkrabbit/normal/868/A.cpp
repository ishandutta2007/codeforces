#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
#include<map>
#define F(i,n) for(int i=1;i<=n;++i)
#define R(i,a,b) for(int i=a;i<=b;++i)
#define dF(i,n) for(int i=n;i>=1;--i)
#define IINF 999999999
using namespace std;
int n,Ans=0;
char a[3];
char st[1001][3];
int h[606],l[606];
int main(){
	scanf("%s",a);
	scanf("%d",&n);
	F(i,n){
		scanf("%s",st[i]);
		if(st[i][0]==a[0]&&st[i][1]==a[1]) Ans=1;
		h[st[i][0]]=1;
		l[st[i][1]]=1;
	}
	if(h[a[1]]&&l[a[0]]) Ans=1;
	if(Ans==1) puts("YES");
	else puts("NO");
	return 0;
}
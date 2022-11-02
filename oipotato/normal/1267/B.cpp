#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int b[300010],tot,n;
char s[300010],a[300010];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,n)if(i==1||s[i]!=s[i-1])tot++,a[tot]=s[i],b[tot]=1;else b[tot]++;
	if(tot%2==0){puts("0");return 0;}
	int pos=(tot+1)/2;
	if(b[pos]<2){puts("0");return 0;}
	rep(i,pos-1)if(a[i]!=a[tot-i+1]||b[i]+b[tot-i+1]<3){puts("0");return 0;}
	printf("%d\n",b[pos]+1);
	return 0;
}
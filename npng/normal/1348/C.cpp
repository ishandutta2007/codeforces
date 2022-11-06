#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,m;char a[N];
void slv(){
	scanf("%d %d %s",&n,&m,a+1);sort(a+1,a+n+1);
	if(a[1]!=a[m]) {putchar(a[m]);puts("");return;}
	if(a[m+1]!=a[n]) {putchar(a[1]);for(int i=m+1;i<=n;++i) putchar(a[i]);}
	else for(int i=1;i<=n;i+=m) putchar(a[i]);puts("");
}
int main(){
	scanf("%d",&T);
	while(T--){
		slv();
	}
	return 0;
}
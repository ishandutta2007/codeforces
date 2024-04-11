#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
#include<map>
#define F(i,n) for(int i=1;i<=n;++i)5
#define R(i,a,b) for(int i=a;i<=b;++i)
#define dF(i,n) for(int i=n;i>=1;--i)
#define IINF 999999999
using namespace std;
int n,m;
int x[5];
int a[17];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) scanf("%d",&x[j]);
		a[x[1]+x[2]*2+x[3]*4+x[4]*8]=1;
	}
	if(a[0]) {puts("YES"); return 0;}
	else{
		for(int i=0;i<16;++i)
			for(int j=0;j<16;++j){
				if((i&j)==0&&a[i]&&a[j]){
					puts("YES");
					return 0;
				}
			}
	}
	puts("NO");
	return 0;
}
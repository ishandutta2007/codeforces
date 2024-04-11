#include <cstdio>

using namespace std;

int a[150],n,m;
int mx = 0;
int l,r;

int main(){
	scanf("%d %d\n",&n,&m);
	for(int i = 0;i<n;i++) scanf("%d",a+i);
	for(int i = 0;i<m;i++){
		scanf("%d %d",&l,&r);
		l--;r--;
		int su = 0;
		for(int j = l;j<=r;j++){
			su += a[j];
		}
		if(su > 0) mx += su;
	}
	printf("%d\n",mx);
}
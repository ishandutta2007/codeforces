#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
int n,m;
int a[Maxn+5];
int b[Maxn+5];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		m=0;
		for(int i=1,j;i<=n;i=j+1){
			j=i;
			while(j<=n&&a[i]==a[j]){
				j++;
			}
			j--;
			b[++m]=j-i+1;
		}
		sort(b+1,b+1+m,cmp);
		int num=0;
		for(int i=1;i<=m;i++){
			if(b[i]==b[1]){
				num++;
			}
		}
		printf("%d\n",(n-num)/(b[1]-1)-1);
	}
	return 0;
}
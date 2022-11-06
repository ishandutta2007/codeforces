#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
int a[Maxn+5];
int b[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int len=0;
	for(int i=1,j=(n>>1)+1;i<=(n>>1);i++,j++){
		b[++len]=a[j];
		b[++len]=a[i];
	}
	int ans=0;
	if(n&1){
		b[n]=a[n];
	}
	for(int i=2;i<n;i++){
		if(b[i]<b[i-1]&&b[i]<b[i+1]){
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	puts("");
	return 0;
}
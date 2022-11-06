#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
int n;
int a[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		int ans=1;
		for(int i=1;i<=n;i++){
			if(i>=a[i]){
				ans=i+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
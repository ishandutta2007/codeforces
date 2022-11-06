#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5],b[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int minn=Inf;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			minn=min(minn,a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+1+n);
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]==b[i]||a[i]%minn==0){
				continue;
			}
			flag=0;
			break;
		}
		if(flag){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}
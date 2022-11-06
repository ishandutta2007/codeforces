#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
typedef long long ll;
int n,x;
int a[Maxn+5];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n,cmp);
		ll sum=0;
		for(int i=1;i<=n+1;i++){
			sum+=a[i];
			if(1ll*i*x>sum||i>n){
				printf("%d\n",i-1);
				break;
			}
		}
	}
	return 0;
}
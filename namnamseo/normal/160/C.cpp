#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
int data[100010];

int main(){
	ll k;
	scanf("%d%I64d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",data+i);
	sort(data+1,data+n+1);
		ll cur=0;
		for(int i=1; i<=n; ++i){
			int j;
			for(j=i+1; j<=n && data[j]==data[i]; ++j); --j;
			if(cur+1<=k && k<=cur+(j-i+1)*1LL*n){
				printf("%d %d\n",data[i], data[(k-cur-1)/(j-i+1)+1]);
				break;
			} else cur += (j-i+1)*1LL*n;
			i=j;
		}
	return 0;
}
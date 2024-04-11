#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 10010;
typedef long long ll;
ll p[N],s[N],d[N];
int main(){
	int n;ll c;scanf("%d %I64d",&n,&c);
	for(int i=0;i<n;i++){
		scanf("%I64d",p+i);
	}
	for(int i=0;i<n;i++){
		scanf("%I64d",s+i);
	}
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+s[i-1];
		for(int j=i-1;j;j--){
			d[j]=min(d[j]+p[i-1]+j*c,d[j-1]+s[i-1]);
		}
		d[0]=d[0]+p[i-1];
	}
	printf("%I64d\n",*min_element(d,d+n+1));
}
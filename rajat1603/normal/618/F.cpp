#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
long long a[N];
long long b[N];
int ptr[N];
int dif[N];
int when[N];
int aa , bb;
int cc , dd;
bool swapped;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld" , a + i);
		a[i] += a[i - 1];
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld" , b + i);
		b[i] += b[i - 1];
	}
	if(a[n] > b[n]){
		for(int i = 1 ; i <= n ; ++i){
			swap(a[i] , b[i]);
		}
		swapped = 1;
	}
	memset(when , -1 , sizeof(when));
	int cur = 0;
	for(int i = 0 ; i <= n ; ++i){
		while(b[cur] < a[i]){
			++cur;
		}
		ptr[i] = cur;
		dif[i] = b[cur] - a[i];
		if(when[dif[i]] != -1){
			aa = when[dif[i]] + 1;
			bb = i;
			cc = ptr[when[dif[i]]] + 1;
			dd = ptr[i];
			break;
		}
		when[dif[i]] = i;
	}
	if(swapped){
		swap(aa , cc);
		swap(bb , dd);
	}
	printf("%d\n" , bb - aa + 1);
	for(int i = aa ; i <= bb ; ++i){
		printf("%d " , i);
	}
	printf("\n%d\n" , dd - cc + 1);
	for(int i = cc ; i <= dd ; ++i){
		printf("%d " , i);
	}
	printf("\n");
}
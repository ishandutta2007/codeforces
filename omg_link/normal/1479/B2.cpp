#include <stdio.h>
#include <algorithm>
#define MN 100000

int n,a[MN+5],f[MN+5],bsc;
bool e[MN+5];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int min = 0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]) continue;
		//1. cover current char : f[j] += 1
		//2. after same char : f[a[i-1]] = f[a[i]]
		//3. after other char : f[j] = min(f[k]+1)
		//f[j] = f[j]
		//f[a[i-1]] = min(f[a[i]]-1,f[j])
		bsc++;
		f[a[i-1]] = min;
		if(e[a[i]]) f[a[i-1]] = std::min(f[a[i-1]],f[a[i]]-1);
		min = std::min(min,f[a[i-1]]);
		e[a[i]] = true;
	}
	printf("%d\n",min+bsc);
}
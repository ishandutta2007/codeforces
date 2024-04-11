#include <stdio.h>
#include <string.h>
#include <algorithm>
#define A first
#define B second

using namespace std;

typedef pair<char *,int> psi;
char str[100010][40];
psi arr[100010];
int opt[100010];
int ans[100010];
int n;

int cmp(psi a,psi b) {
	int k = strcmp(a.A,b.A);
	if(k < 0) return 1;
	if(k > 0) return 0;
	return a.B < b.B;
}
int main() {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%s",str[i]);
		arr[i].A = str[i];
		arr[i].B = i;
	}
	sort(arr,arr+n,cmp);
	for(i=0;i<n;i++) {
		if(i!=0 && strcmp(arr[i].A,arr[i-1].A) == 0) {
			ans[arr[i].B] = opt[i] = opt[i-1]+1;
		}else {
			ans[arr[i].B] = opt[i] = 0;
		}
	}
	for(i=0;i<n;i++) {
		if(ans[i])
			printf("%s%d\n",str[i],ans[i]);
		else
			printf("OK\n");
	}
	return 0;
}
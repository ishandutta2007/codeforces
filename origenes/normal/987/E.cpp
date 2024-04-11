#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=1234567;
int n, a[maxn], pos[maxn], cnt=0;
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		pos[a[i]]=i;
	}
	for(int i=1; i<=n; i++){
		while(a[i]!=i){
			swap(a[i], a[pos[i]]);
			pos[a[pos[i]]]=pos[i];
			cnt++;
		}
	}
	if((n-cnt)&1) puts("Um_nik");
	else puts("Petr");
	return 0;
}
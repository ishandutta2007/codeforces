#include <stdio.h>
#define MN 200000
int n,a[MN+5];
bool check1(){
	for(int i=1;i<=n;i++)
		if(a[i] != i) return false;
	return true;
}
bool check2(){
	int i = 1, state = 1;
	for(;i<=n;i++)
		if(a[i] != i){
			state++;
			i++;
			break;
		}
	for(;i<=n;i++)
		if(a[i] == i){
			state++;
			i++;
			break;
		}
	for(;i<=n;i++)
		if(a[i] != i){
			state++;
			i++;
			break;
		}
	return state != 4;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(check1()){puts("0");return;}
	if(check2()){puts("1");return;}
	puts("2");
}
int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}
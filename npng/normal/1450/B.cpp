#include <cstdio>
int abs(int a){
	return a<0?-a:a;
}
const int Maxn=100;
struct Node{
	int x,y;
}a[Maxn+5];
int n,k;
bool check(int x){
	for(int i=1;i<=n;i++){
		if(abs(a[i].x-a[x].x)+abs(a[i].y-a[x].y)>k){
			return 0;
		}
	}
	return 1;
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=n;i++){
		if(check(i)){
			puts("1");
			return;
		}
	}
	puts("-1");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
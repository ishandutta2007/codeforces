#include<bits/stdc++.h>
using namespace std;
int n,m,now=1;
struct space{
	int a;
	int id;
	bool operator <(const space &b)const{
		return a<b.a;
	}
}a[100010];
struct city{
	int d,g;
	bool operator <(const city &b)const{
		return d<b.d;
	}
}b[100010];
long long ans[100010];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].a),a[i].id=i;
	for(int i=1;i<=m;i++) scanf("%d %d",&b[i].d,&b[i].g);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	long long tmp=0;
	for(int i=1;i<=m;i++){
		while(a[now].a<b[i].d&&now<=n) ans[a[now].id]=tmp,now++;
		tmp+=max(b[i].g,0);
	}
	while(a[now].a>=b[m].d&&now<=n) ans[a[now].id]=tmp,now++;
	for(int i=1;i<=n;i++){
		printf("%I64d ",ans[i]);
	}
}
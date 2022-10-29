#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=1e5+9;
int a[N];
void ask(int x){
	if(a[x])return;
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&a[x]);
	a[x];
}
int main(){
	int n;
	scanf("%d",&n);
	a[0]=a[n+1]=n;
	int l=0,r=n+1;
	int now=1;
	ask(now);
	while(l+2<r){
		if(now-l>r-now){
			int pos=l+now>>1;
			ask(pos);
			if(a[pos]<a[now])r=now,now=pos;
			else l=pos;
		}
		else{
			int pos=now+r>>1;
		//	cout<<pos<<"pos\n";
			ask(pos);
			if(a[pos]<a[now])l=now,now=pos;
			else r=pos;
		}
	//	cout<<l<<' '<<now<<' '<<r<<"check\n";
	}
	printf("! %d\n",now);
	fflush(stdout);
}
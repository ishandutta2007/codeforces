#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cnt;
int a[300005],p[300005];
pii ans[1500005];

void move(int x,int y){
	ans[++cnt]=mp(x,y);
	swap(p[a[x]],p[a[y]]);
	swap(a[x],a[y]);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),p[a[i]]=i;
	if(p[1]==1);
	else if(p[1]<=n/2){
		move(p[1],n);
		move(1,n);
	}
	else move(1,p[1]);
	for(int i=2;i<=n;i++){
		if(p[i]==i) continue;
		if(fabs(p[i]-i)>=n/2){
			move(p[i],i);
			continue;
		}
		if(p[i]<=n/2) move(p[i],n);
		if(fabs(p[i]-i)>=n/2){
			move(p[i],i);
			continue;
		}
		if(p[i]>n/2){
			int tmp=p[i];
			move(1,p[i]);
			if(i<=n/2) move(1,n),move(tmp,1),move(n,i);
			else move(1,i),move(tmp,1);
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}
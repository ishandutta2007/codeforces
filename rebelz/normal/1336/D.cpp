#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,now1,now2;
int ans[105],a[105];
bool vis[105];
int lab[1000005];

pii ask(int x){
	printf("+ %d\n",x);
	fflush(stdout);
	pii ret;
	ret.fi=readint(),ret.se=readint();
	return ret;
}

bool check(){
	for(int i=1;i<=n-2;i++){
		if(vis[i+2]){
			ll k=a[i];
			if(i>=3) k-=ans[i-1]*ans[i-2];
			if(i>=2) k-=(ans[i+1]+1)*(i==2?ans[i-1]+1:ans[i-1]);
			ans[i+2]=k/(ans[i+1]+1)-1;
			if(i+2==n) ans[n]++;
		}
	}
	for(int i=1;i<=n;i++){
		ll k=a[i];
		if(i>=3) k-=(ans[i-1]+1)*(ans[i-2]+1);
		if(i>=2&&i+1<=n) k-=(ans[i-1]+1)*ans[i+1];
		if(i+2<=n) k-=ans[i+1]*ans[i+2];
		if(k!=0) return false;
	}
	return true;
}

int main(){
	n=readint();
	for(int i=2;i<=n;i++) lab[i*(i-1)/2]=i;
	now1=readint(); now2=readint();
	vis[n]=1;
	for(int i=n-1;i>=3;i--){
		pii tmp=ask(i);
		if(tmp.fi-now1>0) ans[i]=lab[tmp.fi-now1];
		else vis[i]=1;
		a[i]=tmp.se-now2;
		now1=tmp.fi,now2=tmp.se;
	}
	pii tmp=ask(1);
	if(tmp.se-now2==0) ans[2]=0;
	else ans[2]=1;
	if(tmp.fi-now1>0) ans[1]=lab[tmp.fi-now1];
	now1=tmp.fi,now2=tmp.se;
	tmp=ask(2);
	if(tmp.fi-now1>0) ans[2]=lab[tmp.fi-now1];
	a[2]=tmp.se-now2;
	now1=tmp.fi,now2=tmp.se;
	tmp=ask(1);
	if(tmp.fi-now1==1) ans[1]=1;
	else if(tmp.fi-now1==0) ans[1]=0;
	a[1]=tmp.se-now2;
	check();
	printf("! ");
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
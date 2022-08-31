#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[100005],vis[100005],ans[100005];

int ask1(int x,int y){
	printf("XOR %d %d\n",x,y);
	fflush(stdout);
	return readint();
}

int ask2(int x,int y){
	printf("AND %d %d\n",x,y);
	fflush(stdout);
	return readint();
}

int main(){
	n=readint();
	for(int i=2;i<=n;i++) a[i]=ask1(1,i);
	vis[0]=1;
	int t1=0,t2=0;
	for(int i=2;i<=n;i++){
		if(vis[a[i]]){
			t1=vis[a[i]],t2=i;
			break;
		}
		vis[a[i]]=i;
	}
	if(!t1){
		for(int i=2;i<=n;i++){
			if(a[i]==1){
				t1=i;
				break;
			}
		}
		for(int i=2;i<=n;i++){
			if(a[i]==2){
				t2=i;
				break;
			}
		}
		ans[1]|=ask2(1,t1)|ask2(1,t2);
		for(int i=2;i<=n;i++) ans[i]=ans[1]^a[i];
	}
	else{
		ans[1]=ask2(t1,t2)^a[t1];
		for(int i=2;i<=n;i++) ans[i]=ans[1]^a[i];
	}
	printf("! ");
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}
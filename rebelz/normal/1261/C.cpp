#include<bits/stdc++.h>

#define y1 dmytxdy
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

int n,m;
int a[2000005],s[2000005],lab[2000005];
char str[1000005];

int id(int x,int y){return (!x||!y)?0:(x-1)*m+y;}

bool check(int x,bool kp){
	memset(lab,0,sizeof(lab));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i<x||j<x||i>n-x||j>m-x) continue;
			int tmp=s[id(i+x,j+x)]-s[id(i-x-1,j+x)]-s[id(i+x,j-x-1)]+s[id(i-x-1,j-x-1)];
			if(tmp!=(x<<1|1)*(x<<1|1)) continue;
			lab[id(i,j)]=1;
		}
		for(int j=1;j<=m;j++) lab[id(i,j)]+=lab[id(i-1,j)]+lab[id(i,j-1)]-lab[id(i-1,j-1)];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[id(i,j)]==0) continue;
			int dai=min(n,i+x),daj=min(m,j+x),dbi=max(1,i-x),dbj=max(1,j-x);
			if(lab[id(dai,daj)]-lab[id(dai,dbj-1)]-lab[id(dbi-1,daj)]+lab[id(dbi-1,dbj-1)]==0) return false;
		}
	}
	if(kp){
		printf("%d\n",x);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) printf("%c",lab[id(i,j)]-lab[id(i-1,j)]-lab[id(i,j-1)]+lab[id(i-1,j-1)]==0?'.':'X');
			printf("\n");
		}
	}
	return true;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		for(int j=1;j<=m;j++) a[id(i,j)]=str[j]=='X',s[id(i,j)]=a[id(i,j)]+s[id(i,j-1)];
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[id(i,j)]+=s[id(i-1,j)];
	int l=0,r=min(n,m),ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid,0)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	check(ans,1);
	return 0;
}
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

int n,k;

int ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	return readint();
}

void print(int x){
	printf("! %d\n",x);
	fflush(stdout);
}

void find(int x,int v,int r){
	if(v>k){
		int l=1;
		while(l<=r){
			int mid=(l+r)/2,pl=((x-mid)%n+n-1)%n+1,val1=ask(pl),val2=ask(pl);
			if(val1==k&&val2==k) return print(pl);
			if(val1>k||val2>k) l=mid+1;
			else r=mid-1;
		}
		assert(0);
	}
	else{
		int l=1;
		while(l<=r){
			int mid=(l+r)/2,pl=(x+mid-1)%n+1,val1=ask(pl),val2=ask(pl);
			if(val1==k&&val2==k) return print(pl);
			if(val1<k||val2<k) l=mid+1;
			else r=mid-1;
		}
		assert(0);
	}
}

int main(){
	n=readint(); k=readint();
	int b=sqrt(n),s=(n-1)/b+1;
	for(int i=1;i<=b;i++) ask(1);
	for(int i=b+1;i<=b+s;i++){
		int tmp=ask((i-b-1)*s+1);
		if(tmp!=k){
			find((i-b-1)*s+1,tmp,min(n/2,(i-b)*2+b-1));
			return 0;
		}
		tmp=ask((i-b-1)*s+1);
		if(tmp!=k){
			find((i-b-1)*s+1,tmp,min(n/2,(i-b)*2+b));
			return 0;
		}
	}
	int tmp=ask(2);
	if(tmp!=k){
		find(2,tmp,min(n/2,b+s*2));
		return 0;
	}
	return 0;
}
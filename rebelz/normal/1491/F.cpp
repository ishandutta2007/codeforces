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

int n;

int ask(int x,int y){
	printf("? 1 1\n");
	printf("%d\n",x);
	printf("%d\n",y);
	fflush(stdout);
	return readint();
}

int ask1(int i,int l,int r){
	printf("? %d %d\n",1,r-l+1);
	printf("%d\n",i);
	for(int j=l;j<=r;j++) printf("%d ",j);
	printf("\n");
	fflush(stdout);
	return readint();
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		int pl=n,val=0;
		for(int i=1;i<n;i++){
			int tmp=ask1(i,i+1,n);
			if(tmp!=0){
				pl=i,val=tmp;
				break;
			}
		}
		vector<int> ans(0);
		int tv=val;
		val++;
		for(int i=pl+1;i<n;i++){
			int tmp=ask(pl,i);
			if(tmp==0) ans.pb(i);
			tv-=tmp;
		}
		if(!tv) ans.pb(n);
		while(pl>1&&val){
			ans.pb(pl-1);
			pl--;
		}
		if(!val&&pl>1){
			int l=1,r=pl-1,res=0,fl=0;
			while(l<r){
				int mid=(l+r)/2,tmp=ask1(pl,l,mid);
				if(tmp==0) l=mid+1;
				else r=mid,fl=1;
			}
			res=l;
			for(int i=1;i<pl;i++) if(i!=res) ans.pb(i);
			if(!fl&&ask(pl,res)==0) ans.pb(res);
		}
		printf("! %d ",ans.size());
		for(auto r:ans) printf("%d ",r);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}
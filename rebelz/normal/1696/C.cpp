// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;
vector<pii> va,vb;

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		va.clear(),vb.clear();
		int x;
		for(int i=1;i<=n;i++){
			x=readint();
			int num=1;
			while(x%m==0) x/=m,num*=m;
			va.pb(mp(x,num));
		}
		k=readint();
		for(int i=1;i<=k;i++){
			x=readint();
			int num=1;
			while(x%m==0) x/=m,num*=m;
			vb.pb(mp(x,num));
		}
		int pa=0,pb=0,fl=0;
		while(pa<va.size()&&pb<vb.size()){
			if(va[pa].fi!=vb[pb].fi){
				fl=1;
				break;
			}
			int mina=min(va[pa].se,vb[pb].se);
			va[pa].se-=mina,vb[pb].se-=mina;
			if(!va[pa].se) pa++;
			if(!vb[pb].se) pb++;
		}
		if(pa<va.size()||pb<vb.size()||fl) puts("No");
		else puts("Yes");
	}
	return 0;
}
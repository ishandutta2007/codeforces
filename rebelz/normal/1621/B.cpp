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

int n;

int main(){
	int T=readint();
	while(T--){
		n=readint();
		int mina=1000000000+1,maxa=0,minb=0,maxb=0;
		ll ans=0;
		int l,r,c;
		int optl=1000000000+1,optr=0,optc=1<<30;
		for(int i=1;i<=n;i++){
			l=readint(); r=readint(); c=readint();
			if(chkmax(maxa,r)) ans+=c-maxb,maxb=c;
			else if(maxa==r) ans+=min(c,maxb)-maxb,chkmin(maxb,c);
			if(chkmin(mina,l)) ans+=c-minb,minb=c;
			else if(mina==l) ans+=min(c,minb)-minb,chkmin(minb,c);
			if(l==mina&&r==maxa){
				if(optl!=mina||optr!=maxa) optl=l,optr=r,optc=c;
				else if(chkmin(optc,c)) optl=l,optr=r,optc=c;
			}
			if(optl==mina&&optr==maxa) printf("%lld\n",min(ans,(ll)optc));
			else printf("%lld\n",ans);
		}
	}
	return 0;
}
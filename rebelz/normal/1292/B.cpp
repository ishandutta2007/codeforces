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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll ax,ay,bx,by,t,m;
pll pl[65],now;

pll f(pll x){return mp(x.fi*ax+bx,x.se*ay+by);}
ll myabs(ll x){return x<0?-x:x;}
ll dist(pll x,pll y){return myabs(x.fi-y.fi)+myabs(x.se-y.se);}

int main(){
	pl[0].fi=readint(),pl[0].se=readint();
	ax=readint(); ay=readint(); bx=readint(); by=readint();
	now.fi=readint(),now.se=readint(); t=readint();
	while(max(pl[m].fi,pl[m].se)<=20000000000000000ll) pl[m+1]=f(pl[m]),m++;
	int ans=0;
	for(int i=0;i<=m;i++){
		for(int j=i;j<=m;j++){
			for(int k=i;k<=j;k++){
				ll res=dist(now,pl[k]),fl=0;
				if(res>t) fl=1;
				for(int l=i;l<k;l++){
					res+=dist(pl[l],pl[l+1]);
					if(res>t) fl=1;
				}
				if(k<j) res+=dist(pl[i],pl[k+1]);
				if(res>t) fl=1;
				for(int l=k+2;l<=j;l++){
					res+=dist(pl[l-1],pl[l]);
					if(res>t) fl=1;
				}
				if(!fl&&res<=t) chkmax(ans,j-i+1);
				res=dist(now,pl[k]),fl=0;
				if(res>t) fl=1;
				for(int l=k+1;l<=j;l++){
					res+=dist(pl[l-1],pl[l]);
					if(res>t) fl=1;
				}
				if(k>i) res+=dist(pl[j],pl[k-1]);
				if(res>t) fl=1;
				for(int l=k-2;l>=i;l--){
					res+=dist(pl[l+1],pl[l]);
					if(res>t) fl=1;
				}
				if(!fl&&res<=t) chkmax(ans,j-i+1);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
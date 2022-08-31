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

int n,m,cl,ce,v,q;
int l[100005],e[100005];

int main(){
	n=readint(); m=readint(); cl=readint(); ce=readint(); v=readint();
	for(int i=1;i<=cl;i++) l[i]=readint();
	for(int i=1;i<=ce;i++) e[i]=readint();
	sort(l+1,l+cl+1);
	sort(e+1,e+ce+1);
	q=readint();
	int x1,y1,x2,y2;
	while(q--){
		x1=readint(); y1=readint(); x2=readint(); y2=readint();
		int t=lower_bound(l+1,l+cl+1,y1)-l,ans=1<<30;
		if(t<=cl) chkmin(ans,abs(l[t]-y1)+abs(x2-x1)+abs(l[t]-y2));
		t--;
		if(t>=1) chkmin(ans,abs(l[t]-y1)+abs(x2-x1)+abs(l[t]-y2));
		t=lower_bound(e+1,e+ce+1,y1)-e;
		if(t<=ce) chkmin(ans,abs(e[t]-y1)+(abs(x2-x1)+v-1)/v+abs(e[t]-y2));
		t--;
		if(t>=1) chkmin(ans,abs(e[t]-y1)+(abs(x2-x1)+v-1)/v+abs(e[t]-y2));
		if(x1==x2) chkmin(ans,abs(y1-y2));
		printf("%d\n",ans);
	}
	return 0;
}
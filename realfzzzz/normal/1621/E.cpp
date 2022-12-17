#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n,m,a[maxn],k[maxn];
vector<int> b[maxn];
ll s[maxn];
int ord[maxn],p[maxn];
bool cmp(int x,int y){
	return s[x]*k[y]>s[y]*k[x];
}
bool chk(int x,int y){
	return s[ord[x]]<=1ll*a[y]*k[ord[x]];
}
int l[maxn],r[maxn];
int get(ll sx,int kx){
	int l=1,r=m+1;
	while(l<r){
		int mid=l+(r-l)/2;
		if(sx*k[ord[mid]]>=s[ord[mid]]*kx) r=mid;
		else l=mid+1;
	}
	return r;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		m=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		sort(a+1,a+n+1,greater<int>());
		for(int i=1;i<=m;i++){
			k[i]=readint();
			vector<int>().swap(b[i]);
			s[i]=0;
			for(int j=0;j<k[i];j++){
				b[i].push_back(readint());
				s[i]+=b[i][j];
			}
		}
		for(int i=1;i<=m;i++) ord[i]=i;
		sort(ord+1,ord+m+1,cmp);
		for(int i=1;i<=m;i++) p[ord[i]]=i;
		int pre=0,suf=m+1;
		while(pre<m&&chk(pre+1,pre+1)) pre++;
		while(suf>1&&chk(suf-1,suf-1)) suf--;
		for(int i=1;i<m;i++) l[i]=chk(i,i+1)?l[i-1]:i+1;
		r[m+1]=m+1;
		for(int i=m;i>1;i--) r[i]=chk(i,i-1)?r[i+1]:i-1;
		for(int i=1;i<=m;i++) for(int j=0;j<k[i];j++){
			ll sx=s[i]-b[i][j];
			int kx=k[i]-1,x=get(sx,kx);
			if(x<=p[i]) printf(pre>=x-1&&suf<=p[i]+1&&l[p[i]-1]<=x&&sx<=1ll*a[x]*kx?"1":"0");
			else printf(pre>=p[i]-1&&suf<=x&&r[p[i]+1]>=x-1&&sx<=1ll*a[x-1]*kx?"1":"0");
		}
		printf("\n");
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}
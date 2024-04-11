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

int n,l,r;
int cnt1[200005],cnt2[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); l=readint(); r=readint();
		for(int i=1;i<=n;i++) cnt1[i]=cnt2[i]=0;
		for(int i=1;i<=l;i++) cnt1[readint()]++;
		for(int i=1;i<=r;i++) cnt2[readint()]++;
		for(int i=1;i<=n;i++){
			int tmp=min(cnt1[i],cnt2[i]);
			cnt1[i]-=tmp,cnt2[i]-=tmp,l-=tmp,r-=tmp;
		}
		if(l<r){
			swap(l,r);
			for(int i=1;i<=n;i++) swap(cnt1[i],cnt2[i]);
		}
		int num=0;
		for(int i=1;i<=n;i++) num+=cnt1[i]/2;
		if(num>=(l-r)/2) printf("%d\n",r+(l-r)/2);
		else printf("%d\n",r+num+(l-r-2*num));
	}
	return 0;
}
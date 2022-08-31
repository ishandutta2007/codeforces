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

int n,N;
int a[200005],s[200005],lst[400005],ans[200005];
vector<int> v[200005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),v[a[i]].pb(i);
	N=min(100,n);
	int opt=0,maxa=0;
	for(int i=1;i<=N;i++) if(chkmax(maxa,(int)v[i].size())) opt=i;
	for(int i=1;i<=N;i++){
		if(i==opt||!v[i].size()) continue;
		int pl=0;
		for(int j=1;j<=n;j++) s[j]=s[j-1]+(a[j]==opt?-1:0)+(a[j]==i?1:0);
		if(s[n]>0) continue;
		for(int j=n;j>=1;j--){
			if(!lst[s[j]+n]) lst[s[j]+n]=j;
			chkmax(ans[j],lst[s[j-1]+n]);
		}
		for(int j=1;j<=n;j++) lst[s[j]+n]=0;
	}
	int res=0;
	for(int i=1;i<=n;i++) chkmax(res,ans[i]-i+1);
	printf("%d\n",res);
	return 0;
}
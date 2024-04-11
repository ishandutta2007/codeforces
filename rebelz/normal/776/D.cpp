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

int n,m;
int a[100005],f[100005],lck[100005],val[100005];
vector<int> v[100005];

int getf(int x){
	if(x==f[x]) return x;
	int ret=getf(f[x]);
	val[x]=val[x]^val[f[x]];
	f[x]=ret;
	return ret;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int x;
	for(int i=1;i<=m;i++){
		x=readint();
		while(x--) v[readint()].push_back(i);
	}
	for(int i=1;i<=m;i++) lck[i]=-1,f[i]=i;
	for(int i=1;i<=n;i++){
		if(!v[i].size()){
			if(!a[i]) return printf("NO\n"),0;
			else continue;
		}
		if(v[i].size()==1){
			int tg=v[i][0],z=a[i]^1,fx=getf(tg);
			if(tg==fx){
				if(lck[tg]>=0&&lck[tg]!=z) return printf("NO\n"),0;
				lck[tg]=z;
			}
			else{
				if(lck[fx]>=0&&lck[fx]!=(z^val[tg])) return printf("NO\n"),0;
				lck[fx]=z^val[tg];
			}
		}
		else{
			int tg1=v[i][0],tg2=v[i][1],fx1=getf(tg1),fx2=getf(tg2),z=a[i]^1;
			if(fx1==fx2){
				if((val[tg1]^val[tg2])!=z) return printf("NO\n"),0;
			}
			else{
				f[fx1]=fx2;
				val[fx1]=z^val[tg1]^val[tg2];
				if(lck[fx1]>=0&&lck[fx2]>=0&&(lck[fx1]^val[fx1])!=lck[fx2]) return printf("NO\n"),0;
				if(lck[fx1]>=0) lck[fx2]=lck[fx1]^val[fx1];
			}
		}
	}
	printf("YES\n");
	return 0;
}
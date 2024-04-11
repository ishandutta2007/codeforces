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
int a[20],b[20],c[20];
int d[66000][200];

int main(){
	n=readint();
	int sa=0,sb=0; char str[5];
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		if(str[0]=='R') c[i]=0;
		else c[i]=1;
		a[i]=readint(); b[i]=readint();
		sa+=a[i],sb+=b[i];
	}
	memset(d,-0x3f,sizeof(d));
	d[0][0]=0;
	for(int i=0;i<(1<<n)-1;i++){
		int cnt[2]={0,0},num=0;
		for(int j=1;j<=n;j++) if((i>>(j-1))&1) cnt[c[j]]++,num++;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1) continue;
			for(int k=0;k<=num*(num-1)/2;k++) chkmax(d[i+(1<<(j-1))][k+min(a[j],cnt[0])],d[i][k]+min(b[j],cnt[1]));
		}
	}
	int ans=1<<30;
	for(int i=0;i<=n*(n-1)/2;i++) chkmin(ans,max(sa-i,sb-d[(1<<n)-1][i]));
	printf("%d\n",ans+n);
	return 0;
}
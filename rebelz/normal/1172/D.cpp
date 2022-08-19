#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cnt;
int a[1000005],b[1000005],ans1[1000005],ans2[1000005],ans3[1000005],ans4[1000005];

void solve(int m){
	if(m==0) return;
	if(a[m]==m&&b[m]==m) return solve(m-1);
	ans1[++cnt]=a[m],ans2[cnt]=m,ans3[cnt]=m,ans4[cnt]=b[m];
	for(int i=1;i<=m;i++){
		if(a[i]==m) a[i]=a[m];
		if(b[i]==m) b[i]=b[m];
	}
	solve(m-1);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) b[i]=readint();
	solve(n);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) printf("%d %d %d %d\n",ans1[i],ans2[i],ans3[i],ans4[i]);
	return 0;
}
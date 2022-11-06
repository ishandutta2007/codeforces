#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=105;
int n,a[Maxn],t;
void mian(){
	scanf("%d %d",&n,&t);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int j=2;j<=n;j++){
		int d=j-1;
		int w=min(a[j],t/d);
		a[1]+=w;
		t-=w*d;
	}
	printf("%d\n",a[1]);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		mian();
	}
}
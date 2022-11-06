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
int n,a[Maxn],b[Maxn];
void mian(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(a+1,a+1+n);sort(b+1,b+1+n);
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	for (int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		mian();
	}
}
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
const int Maxn=100005;
int a[Maxn];
void mian(){
	int n,x;
	scanf("%d %d",&n,&x);
	int Mx=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		Mx=max(Mx,a[i]);
	}
	for (int i=1;i<=n;i++){
		if (a[i]==x){
			printf("1\n");
			return;
		}
	}
	int ans=(x+Mx-1)/Mx;
	if (ans==1) ans=2;
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		mian();
	}
	return 0;
}
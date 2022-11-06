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
int n,a[Maxn];
void mian(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int Mx=-1e9;
	int S=0;
	for (int i=1;i<=n;i++){
		Mx=max(Mx,a[i]);
		S=max(S,Mx-a[i]);
	}
	if (S==0){
		printf("0\n");
		return;
	}
	int x=log2(S)+1;
	printf("%d\n",x);
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		mian();
	}
}
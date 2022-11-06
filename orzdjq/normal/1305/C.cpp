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
const int Maxn=200005;
int n,m;
int a[Maxn];
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (m<n){
		printf("0\n");
		return 0;
	}
	int ans=1;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			int t=abs(a[i]-a[j])%m;
			ans=ans*t%m;
		}
	}
	printf("%d\n",ans);
	return 0;
}
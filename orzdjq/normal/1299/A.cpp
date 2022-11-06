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
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=30;i>=0;i--){
		int cnt=0,id;
		for (int j=1;j<=n;j++){
			if (a[j]>>i&1) cnt++,id=j;
		}
		if (cnt==1){
			swap(a[id],a[1]);
			for (int j=1;j<=n;j++){
				printf("%d ",a[j]);
			}
			printf("\n");
			return 0;
		}
	}
	for (int j=1;j<=n;j++){
		printf("%d ",a[j]);
	}
	printf("\n");
	return 0;
}
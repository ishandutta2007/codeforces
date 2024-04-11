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
int cnt[10005];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int S=0;
	for (int i=n-2;i>=0;i-=2) S+=i;
	if (m>S){
		printf("-1\n");
		return 0;
	}
	if (n==1){
		printf("1\n");return 0;
	}
	if (n==2){
		printf("1 2\n");return 0;
	}
	int curs=0,I;
	for (int i=3;i<=n;i++){
		if (curs+(i-1)/2>=m){
			I=i-1;
			break;
		}
		curs+=(i-1)/2;
	}
	for (int i=1;i<I;i++){
		for (int j=i+1;j<=I;j++) cnt[i+j]++;
	}
	for (int i=I+1;i<=10000;i++){
		if (curs+cnt[i]==m){
			for (int j=1;j<=I;j++){
				printf("%d ",j);
			}
			printf("%d ",i);
			for (int j=I+2;j<=n;j++){
				int rm=-10000*(n-j)+1000000000;
				printf("%d ",rm);
			}
			printf("\n");
			return 0;
		}
	}
}
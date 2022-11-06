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
const int Maxn=400005;
int n,a[Maxn],b[Maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int res=0;
	for (int i=1;i<26;i++){
		int msk=(1<<i)-1;
		for (int j=1;j<=n;j++) b[j]=a[j]&msk;
		sort(b+1,b+1+n);
		int L1=1<<(i-1),L2=L1*2,L3=L1*3;
		int p1=n,p2=n,p3=n;
		int rs=0;
		for (int j=1;j<=n;j++){
			while (p1>=1 && b[p1]+b[j]>=L1) p1--;
			while (p2>=1 && b[p2]+b[j]>=L2) p2--;
			while (p3>=1 && b[p3]+b[j]>=L3) p3--;
			rs+=p2-p1;
			rs+=n-p3;
			if (j>=p1+1 && j<=p2) rs--;
			if (j>=p3+1) rs--;
		}
		rs/=2;
		//cout<<i<<' '<<rs<<endl;
		if (rs&1) res|=1<<(i-1);
	}
	printf("%d\n",res);
	return 0;
}
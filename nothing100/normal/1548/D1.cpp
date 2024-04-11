#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,a[6060],b[6060],num[3][3];
LL ans;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for (int i=0;i<n;i++){
		a[i]>>=1;
		b[i]>>=1;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++)
			if (i!=j) num[(a[i]-a[j])&1][(b[i]-b[j])&1]++;
		for (int h1=0;h1<2;h1++)
		for (int h2=0;h2<2;h2++)
		for (int o1=0;o1<2;o1++)
		for (int o2=0;o2<2;o2++){
			if (!(((h1|h2)+(o1|o2)+(((h1-o1)&1)|((h2-o2)&1)))&1)){
				ans=ans+num[h1][h2]*num[o1][o2];
				if (h1==o1&&h2==o2) ans=ans-num[h1][h2];
			}
		}
		memset(num,0,sizeof(num));
	}
	ans=ans/6;
	printf("%lld\n",ans);
}
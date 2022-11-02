#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,l[200010],cnt,b[200010];
LL ans;
pair<int,int> a[200010];
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&l[i]);
		for (int j=0;j<l[i];j++) scanf("%d",&b[j]);
		int f=0;
		for (int j=1;j<l[i];j++)
		if (b[j]>b[j-1]) f=1;
		if (!f){
			cnt++;
			a[2*cnt-2]=make_pair(b[0],0);
			a[2*cnt-1]=make_pair(b[l[i]-1],1);
		}
	}
	ans=1ll*n*n;
	int tmp=0;
	sort(a,a+2*cnt);
	for (int i=0;i<2*cnt;i++){
		//printf("%d %d\n",a[i].first,a[i].second);
		if (a[i].second==0) tmp++;
		else{
			//printf("%d\n",tmp);
			ans-=tmp;
		}
	}
	printf("%lld\n",ans);
}
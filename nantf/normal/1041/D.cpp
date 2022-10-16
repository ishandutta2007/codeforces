#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,h,l[200020],r[200020];
ll suf1[200020],suf2[200020],ans;
int main(){
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++) scanf("%d%d",l+i,r+i);
	for(int i=n;i;i--) suf1[i]=suf1[i+1]+r[i]-l[i];
	for(int i=n-1;i;i--) suf2[i]=suf2[i+1]+l[i+1]-r[i];
	for(int i=1;i<=n;i++){
		int l=1,r=n+1;
		while(l<r){
			int mid=l+r>>1;
			if(suf2[mid]<=suf2[i]-h) r=mid;
			else l=mid+1;
		}
		ans=max(ans,suf1[i]-suf1[l]+h);
	}
	printf("%I64d\n",ans);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
int main(){
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=0;
		if(l&1) ans-=l,l++;
		if(r&1) ans-=r,r--;
		ans+=r-(r-l)/2;
		printf("%d\n",ans);
	}
}
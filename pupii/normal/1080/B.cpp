#include<bits/stdc++.h>
#define il inline
#define vd void
#define int ll
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
main(){
	int q=gi();
	while(q--){
		ll l=gi(),r=gi();
		ll L=l,R=r;
		if(L%2==0)++L;
		if(R%2==0)--R;
		ll ans=-(L+R)*((R-L+2)/2)/2;
		L=l,R=r;
		if(L%2)++L;
		if(R%2)--R;
		ans+=(L+R)*((R-L+2)/2)/2;
		printf("%lld\n",ans);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
ll sqr;
int main(){
	scanf("%d%d",&n,&q);
	sqr=1ll*n*n+1>>1;
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if((x&1)^(y&1)){
			if(x&1) printf("%I64d\n",sqr+1ll*(x>>1)*n+(y>>1));
			else printf("%I64d\n",sqr+1ll*(x>>1)*n-(n+1>>1)+(y+1>>1));
		}
		else{
			if(x&1) printf("%I64d\n",1ll*(x>>1)*n+(y+1>>1));
			else printf("%I64d\n",1ll*(x>>1)*n-(n>>1)+(y+1>>1));
		}
	}
}
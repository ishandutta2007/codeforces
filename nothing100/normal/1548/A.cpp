#include<bits/stdc++.h>
using namespace std;
int n,m,q,f[200020],res;
void add(int x,int y,int p){
	if (x<y) swap(x,y);
	if (p==1){
		if (f[y]==0) res--;
		f[y]++;
	}
	else{
		f[y]--;
		if (f[y]==0) res++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	res=n;
	for (int i=0;i<m;i++){
		int o,p;
		scanf("%d%d",&o,&p);
		add(o,p,1);
	}
	scanf("%d",&q);
	while (q--){
		int o,p,t;
		scanf("%d",&o);
		if (o==3) printf("%d\n",res);
		else{
			scanf("%d%d",&p,&t);
			add(p,t,o);
		}
	}
}
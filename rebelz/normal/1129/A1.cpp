#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int now[5005],xx[5005];
multiset<int> v[5005];

int to(int x,int y){return x<=y?y-x:y-x+n;}

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(),y=readint();
		v[x].insert(y);
	}
	for(int i=1;i<=n;i++){
		auto it=v[i].lower_bound(i);
		xx[i]=it==v[i].end()?*v[i].begin():*it;
	}
	for(int i=1;i<=n;i++){
		ll ans=0;
		for(int j=1;j<=n;j++) if(v[j].size()) ans=max(ans,(ll)(v[j].size()-1)*n+to(i,j)+to(j,xx[j]));
		printf("%lld ",ans);
	}
	puts("");
	return 0;
}
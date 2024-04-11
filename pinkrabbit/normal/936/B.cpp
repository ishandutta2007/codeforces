#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,o,v[2][100001],k[2][100001],t[2][100001];
vector<int> h[100005];
bool D(int u,bool c){
	if(~k[c][u]) return k[c][u];
	if(!h[u].size()) return k[c][u]=c;
	v[c][u]=1;
	for(int i:h[u]) {if(v[c][i]||v[!c][i]) o=1; if(!v[!c][i]&&D(i,!c)) return t[c][u]=i, v[c][u]=0, k[c][u]=1;}
	return v[c][u]=0, k[c][u]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		while(x--) scanf("%d",&y), h[i].push_back(y);
	} scanf("%d",&x);
	memset(k,-1,sizeof k);
	if(D(x,0)){
		puts("Win"); y=1;
		while(x) printf("%d ",x), x=t[y=!y][x];
		return 0;
	} puts(o?"Draw":"Lose");
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 64
#define MM 256

using std::swap;

const int mod = 3;

int n,m;
int e[MN+5][MN+5];

int l;
int a[3000][MM+5];
int x[MM+5];

int inv(int x){
	return x;
}

void swapLine(int l1,int l2,int st=1){
	if(l1==l2) return;
	swap(a[l1][0],a[l2][0]);
	for(int i=st;i<=m;i++)
		swap(a[l1][i],a[l2][i]);
}

void multLine(int l,int x,int st=1){
	a[l][0] = (a[l][0]*x)%mod;
	for(int i=st;i<=m;i++){
		a[l][i] = (a[l][i]*x)%mod;
	}
}

void addKLine(int l1,int k,int l2,int st=1){
	a[l2][0] = (a[l2][0]+k*a[l1][0])%mod;
	for(int i=st;i<=m;i++){
		a[l2][i] = (a[l2][i]+k*a[l1][i])%mod;
	}
}

void printMatrix(){
	for(int i=1;i<=l;i++){
		for(int j=1;j<=m;j++)
			printf("%d%c %c ",a[i][j],'a'+j-1,"+="[j==m]);
		printf("%d\n",a[i][0]);
	}
}

bool solveEquationSet(){
	int lid = 1;
	for(int i=1;i<=m;i++){
		int targetLine = -1;
		for(int j=lid;j<=l;j++)
			if(a[j][i]){
				targetLine = j;
				break;
			}
		if(targetLine==-1) continue;
		swapLine(lid,targetLine,i);
		multLine(lid,inv(a[lid][i]),i);
		for(int j=lid+1;j<=l;j++)
			addKLine(lid,mod-a[j][i],j,i);
		lid++;
	}
	for(int i=lid;i<=l;i++)
		if(a[i][0]) return false;
	int mid = m;
	for(lid--;lid>=1;lid--){
		int curSolve = -1;
		for(int i=1;i<=m;i++)
			if(a[lid][i]){
				curSolve = i;
				break;
			}
		while(mid>curSolve){
			x[mid] = 0;
			mid--;
		}
		x[mid] = a[lid][0];
		for(int i=lid-1;i>=1;i--){
			if(a[i][mid]){
				a[i][0] -= a[i][mid]*x[mid];
				a[i][0] = (a[i][0]%mod+mod)%mod;
			}
		}
		mid--;
	}
	while(mid>=1){
		x[mid] = 0;
		mid--;
	}
	return true;
}

void solve(){
	memset(e,0,sizeof(e));
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&m);
	l = 0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u][v] = e[v][u] = i;
		if(w!=-1){
			++l;
			a[l][0] = w-1;
			a[l][i] = 1;
		}
	}
	for(int p1=1;p1<=n;p1++)
		for(int p2=p1+1;p2<=n;p2++)
			for(int p3=p2+1;p3<=n;p3++){
				if(e[p1][p2]&&e[p2][p3]&&e[p1][p3]){
					++l;
					a[l][e[p1][p2]] = 1;
					a[l][e[p2][p3]] = 1;
					a[l][e[p1][p3]] = 1;
				}
			}
	if(solveEquationSet()){
		for(int i=1;i<=m;i++)
			printf("%d%c",x[i]+1," \n"[i==m]);
	}else{
		puts("-1");
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}
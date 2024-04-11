#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 105
#define M N*N

const int mod=1000000007;
int n,m,a[M],b[M],c[M][N],g1[N][N],g2[N][N],cnt[N][N][N],dp[N][N],len[M];
queue<int> q;
vector<int> a1,a2;
bool flag;

void upd(int &x,LL y){
	x=(x+y)%mod;
}

void solve(int t,int k){
	int L=0;
	q=queue<int>();
	for (int i=k+1;i<=len[t];++i){
		q.push(c[t][i]);
		if (++L>n*2+1) return;
	}
	int x=0,y=0;
	a1.clear();
	int u=b[t];
	if (q.empty()){
		x=u*2+1;
	}
	else{
		if (q.front()!=u) return;
		q.pop();
		while (1){
			a1.push_back(u);
			if (q.empty()){
				x=u*2;
				break;
			}
			int v=q.front(); q.pop();
			int i=g1[u][v];
			if (!i) return;
			for (int j=1;j<=len[i];++j){
				q.push(c[i][j]);
				if (++L>n*2+1) return;
			}
			u=v;
		}
	}
	q=queue<int>();
	for (int i=k;i;--i){
		q.push(c[t][i]);
		if (++L>n*2+1) return;
	}
	a2.clear();
	u=a[t];
	if (q.empty()){
		y=u*2+1;
	}
	else{
		if (q.front()!=u) return;
		q.pop();
		for (int u=a[t];;){
			a2.push_back(u);
			if (q.empty()){
				y=u*2;
				break;
			}
			int v=q.front(); q.pop();
			int i=g2[u][v];
			if (!i) return;
			for (int j=len[i];j;--j){
				q.push(c[i][j]);
				if (++L>n*2+1) return;
			}
			u=v;
		}
	}
	++cnt[y][x][L];
	if (x%2==0&&y%2==0&&!flag){
		flag=1;
		printf("%d\n",L);
		reverse(a2.begin(),a2.end());
		for (size_t i=0;i<a2.size();++i){
			printf("%d ",a2[i]);
		}
		for (size_t i=0;i<a1.size();++i){
			printf("%d ",a1[i]);
		}
		puts("");
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf("%d%d%d",a+i,b+i,len+i);
		g1[a[i]][b[i]]=i;
		g2[b[i]][a[i]]=i;
		for (int j=1;j<=len[i];++j){
			int x; scanf("%d",&x);
			c[i][j]=x;
		}
	}
	for (int i=1;i<=m;++i){
		for (int j=0;j<=len[i];++j){
			solve(i,j);
		}
	}
	if (!flag){
		puts("0");
		puts("");
	}
	
	return 0;
}
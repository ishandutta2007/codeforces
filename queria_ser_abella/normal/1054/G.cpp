#include <bits/stdc++.h>
#define pii pair<int,int>
#define pip pair<int,pii>
#define maxn 2020
#define debug 
#define pb push_back
typedef long long ll;
using namespace std;


const int sz = 62;
char M[maxn][maxn];

ll mask[40][maxn];
ll mrev[40][maxn];

int block[maxn][maxn];

int n,m;

int qtd;
int ret,it;
inline int go(int a,int b){
	
	ret = 0;
	for(it=0;it<qtd;it++) ret += __builtin_popcountll(mask[it][a]&mrev[it][b]);
	return ret;

}

int sgr[maxn];
int foi[maxn];
queue<pii> Q;
int pai[maxn];

queue<int> gf;
int foi_gr[maxn];

void clear_gr(int g){
	if(foi_gr[g]) return;
	foi_gr[g] = 1;
	debug("sgr %d\n",sgr[g]);
	if(sgr[g] == 0) return;
	debug("cgr %d\n",g);
	int a = 0;
	while(M[g][a] == '0' && a < n) a++;
	assert(a < n);
	for(int i=0;i<n;i++)
		if(i != a && M[g][i] == '0'){
			
			block[a][i]--;
			if(block[a][i] == 0){
				debug("add %d %d\n",a,i);
				Q.push(pii(a,i));
			}
		
		}
}

void ev(){

	while(gf.size()){
		clear_gr(gf.front());
		gf.pop();
	}
	

	if(Q.size() == 0)
		return;

	
	
	pii a = Q.front();
	Q.pop();
	if(foi[a.first] || foi[a.second]){
		ev();
		return;
	}
	
	debug("%d pai %d\n",a.first,a.second);
	
	foi[a.first] = 1;
	pai[a.first] = a.second;
	
	int vx = a.first;
	
	for(int i=0;i<m;i++)
		if(M[i][vx] == '1'){
			M[i][vx] = '0';
			sgr[i]--;
			if(sgr[i] == 1)
				gf.push(i);
		}

	while(gf.size()){
		clear_gr(gf.front());
		gf.pop();
	}
	
	ev();
}

int main(){

	int nt;
	scanf("%d",&nt);
	
	while(nt--){
		
		
		scanf("%d%d",&n,&m);
		getchar();
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				block[i][j] = 0;
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
				M[i][j] = getchar();
			getchar();
		}
		
		for(int i=0;i<m;i++){
			sgr[i] = 0;
			foi_gr[i] = 0;
			for(int j=0;j<n;j++)
				sgr[i] += (M[i][j] == '1');
		}
		
		qtd = m/sz;
		if(m%sz) qtd++;
		for(int i=0;i<n;i++)
			for(int j=0;j<qtd;j++)
				mask[j][i] = mrev[j][i] = 0;
		
		for(int i=0;i<n;i++){
			int cur = 0, pos = 0;
			for(int j=0;j<m;j++){
				mask[cur][i] = 2ll * mask[cur][i] + (M[j][i] == '1');
				mrev[cur][i] = 2ll * mrev[cur][i] + (M[j][i] == '0');
				if((j+1)%sz == 0) cur++;
			}
			debug("i %d masks %lld %lld\n",i,mask[0][i],mrev[0][i]);
		}
		debug("qtd %d\n",qtd);
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i != j){
					block[i][j] = go(i,j);
					debug("%d %d -> %d\n",i,j,block[i][j]);	
				}
		
		while(Q.size()) Q.pop();
		
		while(gf.size()) gf.pop();
		
		
		for(int i=0;i<n;i++) foi[i] = 0, pai[i] = -1;
		
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++)
				if(j != i && block[i][j] == 0){
					Q.push(pii(i,j));
					debug("oi\n");
				}
					
		}
		
		for(int i=0;i<m;i++)
			if(sgr[i] <= 1){
				gf.push(i);
				debug("gf + %d\n",i);	
			}
		
		ev();
		int ok = 0;
		int qt = 0;
		for(int i=0;i<n;i++) if(!foi[i]) qt++;
		if(qt == 1) ok = 1;
		if(ok){
			printf("YES\n");
			for(int i=0;i<n;i++)
				if(pai[i] != -1) printf("%d %d\n",i+1,pai[i]+1);
		}
		else
			printf("NO\n");
			
	}
	
}
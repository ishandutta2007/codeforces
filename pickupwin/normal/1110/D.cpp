#include <cstdio>
#include <algorithm>

using std::max;
using std::min;

const int MAXN=1000111, MAXM=1000111;
const int INF=1034567890;

int N, M;

int F[2][9][9];

int Cnt[MAXM];

int Ans;

int main(){
	
	scanf("%d%d", &N, &M);M+=3;
	
	for(int i=1, v;i<=N;++i){
		scanf("%d", &v);
		++Cnt[v];
	}
	
	for(int i=1;i<=M;++i)
		while(Cnt[i]>=9)	{++Ans;Cnt[i]-=3;}
	
	for(int a=0;a<9;++a)
		for(int b=0;b<9;++b)
			F[1][a][b]=-INF;
	
	F[1][0][0]=0;
	for(int i=1, p=1, t=0;i<M;++i, p^=1, t^=1){
		for(int a=0;a<9;++a)
			for(int b=0;b<9;++b)
				F[t][a][b]=-INF;
		for(int a=0;a<9;++a)
			for(int b=0, c, m;b<9;++b){
				c=Cnt[i];
				m=min(c, min(a, b));
				for(int j=0;j<=m;++j){
					F[t][b-j][c-j]=max(F[t][b-j][c-j], F[p][a][b]+j+(a-j)/3);
				}
			}
	}
	
	printf("%d\n", F[M&1][0][0]+Ans);
	
	return 0;
}
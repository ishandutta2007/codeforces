#include <cstdio>

const int MAXN=200011;

int N;

struct Vert{
	int Deg;
} V[MAXN];

int main(){
	
	scanf("%d", &N);
	for(int i=1, a, b;i<N;++i){
		scanf("%d%d", &a, &b);
		++V[a].Deg;++V[b].Deg;
	}
	
	for(int i=1;i<=N;++i){
		if(V[i].Deg==2){
			puts("NO");
			return 0;
		}
	}
	
	puts("YES");
	
	return 0;
}
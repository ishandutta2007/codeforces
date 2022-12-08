#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=1111111;

int N;

struct Point{
	int x, y, id;
} P[MAXN];

bool cmpp(Point A, Point B){
	if(A.x==B.x){
		if(A.x&1)	return A.y<B.y;
		else	return A.y>B.y;
	}
	return A.x<B.x;
}

int main(){
	
	scanf("%d", &N);
	for(int i=1;i<=N;++i){
		scanf("%d%d", &P[i].x, &P[i].y);
		P[i].x/=1000;
		//P[i].x>>=10;
		P[i].id=i;
	}
	
	sort(P+1, P+N+1, cmpp);
	
	for(int i=1;i<=N;++i)
		printf("%d ", P[i].id);
	printf("\n");
	
	return 0;
}
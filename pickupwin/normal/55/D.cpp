#include <cstdio>
#include <cstring>
#include <queue>

using std::queue;

int T;
long long L, R;

int Lc[20], Rc[20];

int Mo[48]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 18, 20, 21, 24, 28, 30, 35, 36, 40, 42, 45, 56, 60, 63, 70, 72, 84, 90, 105, 120, 126, 140, 168, 180, 210, 252, 280, 315, 360, 420, 504, 630, 840, 1260, 2520};
int Tr[48][10];
int Tim[2521];

long long F[20][2][2][2520][48];
long long Ans;

int mo(int k, int d){
	return (k*10+d)%2520;
}

int gcd(int a, int b){
	return (b==0)?a:gcd(b, a%b);
}

int lcm(int a, int b){
	if(b==0)	return a;
	return a*b/gcd(a, b);
}

struct Pos{
	int i, a, b, k, l;
	Pos(){}
	Pos(int _i, int _a, int _b, int _k, int _l){i=_i;a=_a;b=_b;k=_k;l=_l;}
};

queue<Pos> Q;

inline void relax(int i, int a, int b, int k, int l, long long v){
	if(F[i][a][b][k][l]==0LL)
		Q.push(Pos(i, a, b, k, l));
	F[i][a][b][k][l]+=v;
}


int main(){
	
	for(int i=0;i<48;++i){
		Tr[i][0]=i;
		for(int j=1, v;j<10;++j){
			v=lcm(Mo[i], j);
			for(int k=i;k<48;++k){
				if(Mo[k]==v){
					Tr[i][j]=k;
					break;
				}
			}
		}
	}
	
	scanf("%d", &T);
	
	while(T--){
		
		scanf("%I64d%I64d", &L, &R);
		
		for(int i=0;i<20;++i){
			Rc[i]=R%10;
			R/=10;
		}
		
		for(int i=0;i<20;++i){
			Lc[i]=L%10;
			L/=10;
		}
		
		memset(F, 0, sizeof(F));
		
		Ans=0LL;
		relax(19, 1, 1, 0, Tim[1], 1LL);
		for(Pos AT;!Q.empty();){
			AT=Q.front();Q.pop();
			if(AT.i==0){
				if(AT.k%Mo[AT.l]==0){
					Ans+=F[0][AT.a][AT.b][AT.k][AT.l];
				}
				continue;
			}
			int i, l, r;
			i=AT.i;l=(AT.a)?Lc[i-1]:0;r=(AT.b)?Rc[i-1]:9;
			for(int d=l, tk, tl;d<=r;++d){
				tk=mo(AT.k, d);
				tl=Tr[AT.l][d];
				relax(i-1, AT.a && (d==Lc[i-1]), AT.b && (d==Rc[i-1]), tk, tl, F[i][AT.a][AT.b][AT.k][AT.l]);
			}
		}
		
		printf("%I64d\n", Ans);
		
	}
	
	return 0;
}

/*
2
1 9
12 15

*/
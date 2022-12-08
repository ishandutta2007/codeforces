#include <cstdio>
#include <cstring>

const int MAXV=1333;

struct Vert{
	int Tr[10];
} V[MAXV];

int Vcnt;
int Root;
int Pos[11][11][11];

inline int norm(const int &k){
	return (k%11+11)%11;
}

const int MAXL=100011;

int L, A[MAXL];
char input[MAXL];
int F[2][MAXV];

int main(){
	
	Root=++Vcnt;
	for(int a=0;a<11;++a)
		for(int b=0;b<11;++b)
			for(int c=0;c<11;++c)
				Pos[a][b][c]=++Vcnt;
	
	for(int i=1;i<=9;++i){
		V[Root].Tr[i]=Pos[i][i-1][9-i];
	}
	
	for(int a=0, ta;a<11;++a)
		for(int b=0, tb;b<11;++b)
			for(int c=0, tc;c<11;++c){
				for(int d=0;d<a;++d){
					tb=d;
					for(int i=1;i<=b;++i)	tb+=a-i;
					tc=a-1-d;
					for(int i=1;i<=c;++i)	tc+=a+i;
					ta=a+c+tb+1;
					ta=norm(ta);tb=norm(tb);tc=norm(tc);
					V[Pos[a][b][c]].Tr[d]=Pos[ta][tb][tc];
				}
			}
	
	scanf("%s", input);
	L=strlen(input);
	for(int i=1;i<=L;++i)	A[i]=input[i-1]-'0';
	
	long long Ans=0LL;
	
	for(int i=L, n=i&1, p=!n;i>=1;--i, n^=1, p^=1){
		for(int j=1;j<=Vcnt;++j)
			F[n][j]=(V[j].Tr[A[i]])?(F[p][V[j].Tr[A[i]]]+1):0;
		Ans+=F[n][Root];
	}
	
	printf("%I64d\n", Ans);
	
	return 0;
}
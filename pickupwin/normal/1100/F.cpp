#include <cstdio>
#include <algorithm>

using std::sort;
using std::swap;
using std::max;

const int MAXN=1000011, MAXM=1000011;

namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a integer
	template <class I>
	inline void gi (I &x) {
		for (c = gc(); c < '0' || c > '9'; c = gc());
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
	}
	// print a integer
	template <class I>
	inline void print (I &x) {
		if (!x) putc ('0');
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
}
using io :: gi;
using io :: putc;
using io :: print;

int N, M, L;
int A[MAXN];
int B[33][2];

struct Query{
	int l, r, d;
	int id, ans;
} Q[MAXM];

inline bool operator < (const Query &A, const Query &B){
	return A.r<B.r;
}

inline bool cmpid(const Query &A, const Query &B){
	return A.id<B.id;
}

void Insert(int v, int t){
	for(int i=29;i>=0;--i){
		if((v>>i)&1){
			if(B[i][0]){
				if(B[i][1]<t){
					swap(B[i][0], v);
					swap(B[i][1], t);
				}
				v^=B[i][0];
			}
			else	{B[i][0]=v;B[i][1]=t;break;}
		}
	}
}

int Ask(int t, int v){
	for(int i=29;i>=0;--i){
		if((v>>i)&1)	continue;
		if(B[i][1]>=t)	v^=B[i][0];	
	}
	return v;
}

int main(){
	
	//scanf("%d", &N);
	gi(N);
	//for(int i=1;i<=N;++i)	scanf("%d", &A[i]);
	for(int i=1;i<=N;++i)	gi(A[i]);
	//scanf("%d", &M);
	gi(M);
	for(int i=1;i<=M;++i){
		//scanf("%d%d%d", &Q[i].l, &Q[i].r, &Q[i].d);
		gi(Q[i].l);gi(Q[i].r);//gi(Q[i].d);
		Q[i].id=i;
	}
	/*
	for(int i=1;i<=N-L+1;++i){
		++M;
		Q[M].l=i;Q[M].r=i+L-1;Q[M].d=0;	
	}
	*/
	
	sort(Q+1, Q+M+1);
	
	for(int i=1, j=1;i<=M;++i){
		while(j<=N && j<=Q[i].r){
			Insert(A[j], j);
			++j;	
		}
		Q[i].ans=Ask(Q[i].l, Q[i].d);
	}
	
	sort(Q+1, Q+M+1, cmpid);
	
	/*
	int Ans=0;
	for(int i=1;i<=M;++i)	Ans=max(Ans, Q[i].ans);
	printf("%d\n", Ans);
	*/
	//for(int i=1;i<=M;++i)	printf("%d\n", Q[i].ans);
	for(int i=1;i<=M;++i)	{print(Q[i].ans);putc('\n');}
	io::flush();
	
	return 0;	
}
#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

const int MAXN=111111;
const int MAXK=7;

int N, K, M, Qcnt;
bool Ced[MAXN][MAXK];
bool Used[MAXN][MAXK];
int Cnt1[MAXN], Cnt2[MAXN];
int F[MAXN];

int read(){
	int x=0, f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')	f=-f;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}

int Find(int a){
	if(F[F[a]]!=F[a])	F[a]=Find(F[a]);
	return F[a];
}

int main(){
	
	
	N=read();K=read();
	
	M=read();
	for(int i=1, a, b;i<=M;++i){
		a=read();b=read();
		if(a>b)	swap(a, b);
		Ced[a][b-a]=true;
	}
	
	for(int i=1;i<=N;++i)	F[i]=i;
	for(int i=1;i<=K;++i){
		for(int j=1, fx, fy;j<=N;++j){
			if(!Ced[j][i])	continue;
			fx=Find(j);fy=Find(j+i);
			if(fx!=fy){
				Used[j][i]=true;
				F[fx]=fy;
			}
		}
	}
	
	for(int i=1;i<=N;++i)
		for(int j=1;j<=K;++j){
			if(Used[i][j]){
				++Cnt1[i+j];
				++Cnt2[i];
			}
		}
	
	for(int i=1;i<=N;++i){
		Cnt1[i]+=Cnt1[i-1];Cnt2[i]+=Cnt2[i-1];
	}
	
	//for(int i=1;i<=N;++i){
	//	cout << Cnt1[i] << " " << Cnt2[i] << endl;
	//}
	
	int Del=0;
	Qcnt=read();
	for(int a, b;Qcnt--;){
		Del=0;
		a=read();b=read();
		for(int i=a-1;i+K>b;--i)
			for(int k=K;i+k>b;--k)
				if(Used[i][k])	++Del;
		//cout << (b-a+1)-(Cnt1[b]-Cnt2[a-1])-Del << endl;
		printf("%d\n", (b-a+1)-(Cnt1[b]-Cnt2[a-1])-Del);
	}
	
	return 0;
}

/*
10 5
5
8 9
3 8
2 5
1 3
4 7
3
3 3
4 8
4 8

1
4
4

*/
#include <iostream>
using namespace std;
const int MAXN=111;
const int MAXM=1111111;
const long long INF=4567891012345678910LL;
int Bin[22];
int N, M;
long long b;
struct Friend{
	long long x, k;
	int m;
} F[MAXN];
long long lmin(long long a, long long b){
	return (a>b)?b:a;
}
void Qsort(int l, int r){
	int i=l, j=r;
	long long test=F[(l+r)>>1].k;
	Friend temp;
	while(i<=j){
		while(F[i].k<test)	++i;
		while(F[j].k>test)	--j;
		if(i<=j){
			temp=F[i];F[i]=F[j];F[j]=temp;
			++i;--j;
		}
	}
	if(i<r)	Qsort(i, r);
	if(l<j)	Qsort(l, j);
}
long long DP[MAXM], ANS=INF;
int main(){
	ios_base::sync_with_stdio(false);
	Bin[0]=1;
	for(int i=1;i<=21;++i){
		Bin[i]=Bin[i-1]<<1;
	}
	cin >> N >> M >> b;
	for(int i=1, cnt;i<=N;++i){
		cin >> F[i].x >> F[i].k >> cnt;
		F[i].m=0;
		for(int j=cnt, a;j>=1;--j){
			cin >> a;
			F[i].m+=(1<<(a-1));
		}
	}
	Qsort(1, N);
	for(register int i=0;i<Bin[M];++i){
		DP[i]=INF;
	}
	DP[0]=0LL;
	for(int i=1;i<=N;++i){
		for(int j=Bin[M]-1;j>=0;--j){
			if(DP[j]>=INF)	continue;
			DP[j|F[i].m]=lmin(DP[j]+F[i].x, DP[j|F[i].m]);
		}
		ANS=lmin(ANS, DP[Bin[M]-1]+F[i].k*b);
	}
	if(ANS>=INF)	cout << "-1" << endl;
	else cout << ANS << endl;
	return 0;
}
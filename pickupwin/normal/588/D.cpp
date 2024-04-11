#include <iostream>

using namespace std;

const int MAXN=1111111;
const long long MOD=1000000007LL;

int N, K;
long long L, Pos;
long long Num[MAXN];
int NumRank[MAXN];
long long DP[MAXN], SUM, ANS=0LL;

long long sum(long long a, long long b){
	long long ret=a+b;
	if(ret>=MOD)	ret-=MOD;
	return ret;
}

void RankNum(int l, int r){
	int i=l, j=r;
	long long test=Num[NumRank[(l+r)>>1]];
	while(i<=j){
		while(Num[NumRank[i]]<test)	++i;
		while(Num[NumRank[j]]>test)	--j;
		if(i<=j){
			swap(NumRank[i], NumRank[j]);
			++i;--j;
		}
	}
	if(i<r)	RankNum(i, r);
	if(l<j)	RankNum(l, j);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> L >> K;
	
	for(int i=1;i<=N;++i)	cin >> Num[i];
	for(int i=1;i<=N;++i)	NumRank[i]=i;
	
	RankNum(1, N);
	
	for(int k=1;k<=K;++k){
		SUM=0LL;
		if(k==1)	SUM=1LL;
		for(int i=1, j, sp=1;i<=N;++i){
			j=NumRank[i];
			Pos=(long long)((k-1)*N+j);
			while(sp<=N && Num[NumRank[sp]]<=Num[j])	SUM=sum(SUM, DP[sp++]);
			if(Pos>L)	DP[i]=0LL;
			else	DP[i]=SUM;
			ANS=sum(ANS, (((L-Pos)/N+1)%MOD*DP[i])%MOD);
		}
		//for(int i=1;i<=N;++i)
		//	cout << DP[i] << endl;
	}
	
	cout << ANS << endl;
	
	return 0;
}
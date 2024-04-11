#include <iostream>
using namespace std;
const int MAXN=111111;
const long long MOD=1000000007LL;
int N, Ecnt=0;
int FE[MAXN], Co[MAXN];
long long DP[2][MAXN];
struct Edge{
	int x, y, next;
} E[MAXN<<1];
void addE(int a, int b){
	//cout << "addE " << a << " " << b << endl;
	++Ecnt;
	E[Ecnt].x=a;
	E[Ecnt].y=b;
	E[Ecnt].next=FE[a];
	FE[a]=Ecnt;
}
void DFS(int at, int f){
	if(Co[at]>=1){
		DP[0][at]=0LL;
		DP[1][at]=1LL;
		for(int k=FE[at], to;k>0;k=E[k].next){
			to=E[k].y;
			if(to==f)	continue;
			DFS(to, at);
			DP[1][at]*=(DP[0][to]+DP[1][to]);
			DP[1][at]%=MOD;
		}
		return;
	}
	DP[0][at]=1LL;
	DP[1][at]=0LL;
	for(int k=FE[at], to;k>0;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		DFS(to, at);
		DP[1][at]*=(DP[0][to]+DP[1][to]);
		DP[1][at]%=MOD;
		DP[1][at]+=(DP[1][to]*DP[0][at])%MOD;
		DP[1][at]%=MOD;
		DP[0][at]*=(DP[0][to]+DP[1][to]);
		DP[0][at]%=MOD;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(register int i=1;i<=N;++i)
		FE[i]=-1;
	for(int i=2, p;i<=N;++i){
		cin >> p;
		++p;
		addE(p, i);
		addE(i, p);
	}
	for(int i=1;i<=N;++i)
		cin >> Co[i];
	DFS(1, 1);
	/*
	for(int i=1;i<=N;++i){
		cout << i << ":" << DP[0][i] << " " << DP[1][i] << endl;
	}
	*/
	cout << DP[1][1] << endl;
	return 0;
}
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int MAXN=55;
const int MAXL=22;
const int MAXM=1111111;
string input;
int N, L;
char Map[MAXN][MAXL];
long long F[MAXM], Bin[MAXN];
double Cnt[MAXM];
double DP[MAXM];
int cnt1(long long key){
	int ret=0;
	while(key>0LL){
		if(key&1LL)	++ret;
		key>>=1;
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	Bin[0]=1LL;
	for(int i=1;i<=54;++i)
		Bin[i]=Bin[i-1]<<1;
	cin >> N;
	for(int i=0;i<N;++i){
		cin >> input;
		L=input.length();
		for(int j=0;j<L;++j)
			Map[i][j]=input[j];
	}
	//F[(1<<L)-1]=0;
	for(int i=0;i<N;++i){
		for(int j=i+1, k;j<N;++j){
			k=0;
			for(int t=0;t<L;++t){
				if(Map[i][t]==Map[j][t]){
					k|=Bin[t];
				}
			}
			F[k]|=(Bin[i]|Bin[j]);
		}
	}
	for(int i=(1<<L)-1;i>=0;--i){
		for(int j=0;j<L;++j){
			if(!((i>>j)&1)){
				F[i]|=F[i|(1<<j)];
			}
		}
	}
	for(int i=0;i<(1<<L);++i)
		Cnt[i]=double(cnt1(F[i]));
	DP[(1<<L)-1]=0.0;
	for(int i=(1<<L)-1, cnt;i>=0;--i){
		cnt=0;
		for(int j=0;j<L;++j){
			if((i>>j)&1)	continue;
			++cnt;
		}
		if(cnt<=0)	continue;
		if(Cnt[i]<=0){
			DP[i]=0.0;
			continue;
		}
		DP[i]=1.0;
		for(int j=0;j<L;++j){
			if((i>>j)&1)	continue;
			DP[i]+=(DP[i|(1<<j)]*Cnt[i|(1<<j)]/Cnt[i])/(double)(cnt);
		}
	}
	cout << fixed << setprecision(12) << DP[0] << endl;
	return 0;
}
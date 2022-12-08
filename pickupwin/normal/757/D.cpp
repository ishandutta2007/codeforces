#include <iostream>
#include <string>
using namespace std;
const int MAXN=77;
const int MAXM=1111111;
const int MOD=1000000007;
int N, ANS;
string input;
int Bin[21];
int Num[MAXN];
int F[MAXN][MAXM];
int main(){
	ios_base::sync_with_stdio(false);
	Bin[0]=1;
	for(int i=1;i<=20;++i)
		Bin[i]=Bin[i-1]<<1;
	cin >> N;
	cin >> input;
	for(int i=1;i<=N;++i){
		Num[i]=input[i-1]-'0';
	}
	for(int i=0;i<=N;++i)
		for(int j=0;j<Bin[20];++j)
			F[i][j]=0;
	for(int i=0;i<=N;++i)
		F[i][0]=1;
	for(int i=0;i<=N;++i){
		for(int j=0, num;j<Bin[20];++j){
			if(F[i][j]<=0)	continue;
			num=0;
			for(int k=i+1;k<=N;++k){
				num=(num<<1)+Num[k];
				if(num<=0)	continue;
				if(num>20)	break;
				F[k][j|Bin[num-1]]+=F[i][j];
				if(F[k][j|Bin[num-1]]>=MOD)	F[k][j|Bin[num-1]]-=MOD;
			}
		}
	}
	ANS=0;
	for(int i=0;i<=N;++i){
		for(int j=1;j<=20;++j){
			ANS+=F[i][Bin[j]-1];
			if(ANS>=MOD)	ANS-=MOD;
		}
	}
	cout << ANS << endl;
	return 0;
}
#include <iostream>

using namespace std;

const int MAXN=111;
const int MAXM=111;

int N, M;
int A[MAXN], B[MAXM];
int Tot;

int Ad[30][MAXN], Bd[30][MAXM];
int CntA[30], CntB[30];
int Map[MAXN][MAXM];
int Bin[30];

int main(){
	ios_base::sync_with_stdio(false);
	
	Bin[0]=1;
	for(int i=1;i<30;++i)	Bin[i]=Bin[i-1]+Bin[i-1];
	
	cin >> N >> M;
	for(int i=1;i<=N;++i)	cin >> A[i];
	for(int j=1;j<=M;++j)	cin >> B[j];
	
	Tot=0;
	for(int i=1;i<=N;++i)	Tot^=A[i];
	for(int j=1;j<=M;++j)	Tot^=B[j];
	
	if(Tot==0){
		for(int i=1;i<=N;++i)
			for(int k=0;k<30;++k){
				Ad[k][i]=(A[i]&1);
				A[i]>>=1;
			}
		for(int i=1;i<=M;++i)
			for(int k=0;k<30;++k){
				Bd[k][i]=(B[i]&1);
				B[i]>>=1;
			}
		for(int i=0;i<30;++i)
			for(int p=1;p<=N;++p)
				if(Ad[i][p])	++CntA[i];
		for(int i=0;i<30;++i)
			for(int p=1;p<=M;++p)
				if(Bd[i][p])	++CntB[i];
		for(int k=0;k<30;++k){
			if(CntA[k]==0){
				for(int j=1;j<=M;++j)
					if(Bd[k][j])	Map[1][j]+=Bin[k];
			}
			else if(CntB[k]==0){
				for(int i=1;i<=N;++i)
					if(Ad[k][i])	Map[i][1]+=Bin[k];
			}
			else if(CntA[k]&1){
				for(int i=1;i<=N;++i)
					for(int j=1;j<=M;++j)
						if(Ad[k][i] && Bd[k][j])
							Map[i][j]+=Bin[k];
			}
			else{
				if(CntA[k]>CntB[k]){
					int t=CntA[k]-CntB[k];
					int i=0, j=0;
					while(j<M && !Bd[k][j+1])	++j;
					++j;
					while(t--){
						while(i<N && !Ad[k][i+1])	++i;
						++i;
						Map[i][j]+=Bin[k];
					}
					j=0;
					for(t=1;t<=CntB[k];++t){
						while(j<M && !Bd[k][j+1])	++j;
						++j;
						while(i<N && !Ad[k][i+1])	++i;
						++i;
						Map[i][j]+=Bin[k];
					}
				}
				else{
					int t=CntB[k]-CntA[k];
					int i=0, j=0;
					while(i<N && !Ad[k][i+1])	++i;
					++i;
					while(t--){
						while(j<M && !Bd[k][j+1])	++j;
						++j;
						Map[i][j]+=Bin[k];
					}
					i=0;
					for(t=1;t<=CntA[k];++t){
						while(j<M && !Bd[k][j+1])	++j;
						++j;
						while(i<N && !Ad[k][i+1])	++i;
						++i;
						Map[i][j]+=Bin[k];
					}
				}
			}
		}
		cout << "YES" << endl;
		for(int i=1;i<=N;++i){
			for(int j=1;j<=M;++j)
				cout << Map[i][j] << " ";
			cout << endl;
		}
	}
	else	cout << "NO" << endl;
	
	return 0;
}
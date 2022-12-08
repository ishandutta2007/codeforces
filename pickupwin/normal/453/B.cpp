#include <iostream>

using namespace std;

const int INF=1034567890;
const int MAXN=111;

int N;
int Prime[17]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int Num[MAXN];
int Need[67];
int DP[MAXN][133333];
int From[MAXN][133333];
int Put[MAXN][133333];
int Out[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i){
		cin >> Num[i];
	}
	
	for(int i=1;i<=59;++i){
		Need[i]=0;
		for(int j=0;j<17;++j){
			if(i%Prime[j]==0)	Need[i]+=(1<<j);
		}
	}
	
	for(int i=0;i<=N;++i)
		for(int j=0;j<(1<<17);++j)
			DP[i][j]=INF;
	
	DP[0][0]=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<(1<<17);++j){
			if(DP[i][j]>=INF)	continue;
			for(int k=1;k<=59;++k){
				if((Need[k]&j)==0){
					if(DP[i+1][j|Need[k]]>DP[i][j]+abs(k-Num[i+1])){
						DP[i+1][j|Need[k]]=DP[i][j]+abs(k-Num[i+1]);
						From[i+1][j|Need[k]]=j;
						Put[i+1][j|Need[k]]=k;
					}
					//DP[i+1][j|Need[k]]=min(DP[i+1][j|Need[k]], DP[i][j]+abs(k-Num[i]));
				}
			}
		}
	}
	
	int ANS=INF, ANSat=-1;
	for(int i=0;i<(1<<17);++i){
		ANS=min(ANS, DP[N][i]);
		if(ANS==DP[N][i])	ANSat=i;
	}
	
	for(int i=N, j=ANSat;i>=1;j=From[i][j], --i){
		//cout << Put[i][j] << " " << N-i+1 << endl;
		//Out[N-i+1]=Put[i][j];
		Out[i]=Put[i][j];
	}
	
	for(int i=1;i<=N;++i)	cout << Out[i] << " ";
	cout << endl;
	
	return 0;
}
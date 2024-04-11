#include <iostream>
#include <string>

using namespace std;

const int MAXN=2111;
const int MAXM=2111;

int N, M, K;
string input;
int Map[MAXN][MAXM];
int Sum[MAXN][MAXM];
int ANS=0;

int main(){
	ios_base::sync_with_stdio(false);
	
	for(int i=0;i<MAXN;++i)	for(int j=0;j<MAXM;++j)	{Map[i][j]=0;Sum[i][j]=0;}
	
	cin >> N >> M >> K;
	
	for(int i=1;i<=N;++i){
		cin >> input;
		for(int j=1;j<=M;++j){
			if(input[j-1]=='.')	Map[i][j]=1;
			else	Map[i][j]=0;
		}
	}
	
	for(int i=N;i>=1;--i)
		for(int j=M;j>=1;--j)
			Sum[i][j]=Sum[i+1][j]+Sum[i][j+1]-Sum[i+1][j+1]+Map[i][j];
	
	/*
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			cout << Sum[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	if(K==1){
		ANS=Sum[1][1];
	}
	else{
		for(int i=1;i<=N;++i){
			for(int j=1;j<=M;++j){
				if(i+K-1<=N && (Sum[i][j]-Sum[i+K][j]-Sum[i][j+1]+Sum[i+K][j+1])==K)	++ANS;//cout << i << " " << j << " 1" << endl;
				if(j+K-1<=M && (Sum[i][j]-Sum[i][j+K]-Sum[i+1][j]+Sum[i+1][j+K])==K)	++ANS;//cout << i << " " << j << " 2" << endl;
			}
		}
	}
	
	cout << ANS << endl;
	
	return 0;
}

/*
2 3 2
**.
...

3

*/

/*
1 2 2
..

1

*/

/*
3 3 4
.*.
*.*
.*.

0

*/

/*
3 3 1
...
.*.
...

8

*/
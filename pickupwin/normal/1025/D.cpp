#include <iostream>

using namespace std;

const int MAXN=711;

long long gcd(long long a, long long b){
	return (b==0)?a:gcd(b, a%b);
}

int N;
long long Num[MAXN];
long long Gcd[MAXN][MAXN];
bool F[MAXN][MAXN], L[MAXN][MAXN], R[MAXN][MAXN];

bool Test(int a, int b){
	if(a<1 || a>N || b<1 || b>N)	return false;
	return Gcd[a][b]>1LL;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i)	cin >> Num[i];
	
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)	Gcd[i][j]=gcd(Num[i], Num[j]);
	
	for(int i=1;i<=N;++i)	F[i][i]=true;
	for(int i=1;i<=N;++i)	L[i][i]=Test(i, i-1);
	for(int i=1;i<=N;++i)	R[i][i]=Test(i, i+1);
	
	for(int d=1;d<N;++d){
		for(int i=1, j=i+d;j<=N;++i, ++j){
			if(L[i+1][j]){
				F[i][j]=true;
				L[i][j]|=Test(i, i-1);
				R[i][j]|=Test(i, j+1);
			}
			for(int k=i+1;k<j;++k){
				if(R[i][k-1] && L[k+1][j]){
					F[i][j]=true;
					L[i][j]|=Test(k, i-1);
					R[i][j]|=Test(k, j+1);
				}
			}
			if(R[i][j-1]){
				F[i][j]=true;
				L[i][j]|=Test(j, i-1);
				R[i][j]|=Test(j, j+1);
			}
		}
	}
	
	/*
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j){
			if(F[i][j])	cout << "F " << i << " " << j << endl;
			if(L[i][j])	cout << "L " << i << " " << j << endl;
			if(R[i][j])	cout << "R " << i << " " << j << endl;
		}
	*/
	
	if(F[1][N])	cout << "Yes" << endl;
	else	cout << "No" << endl;
	
	return 0;
}
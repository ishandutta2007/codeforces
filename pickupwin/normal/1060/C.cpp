#include <iostream>

using namespace std;

const int MAXN=2111;
const int MAXM=2111;
const int MAXV=2111;

int N, M, X;
int A[MAXN], SumA[MAXN], B[MAXM], SumB[MAXM];
int LenB[MAXM*MAXV];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=1;i<=N;++i)	cin >> A[i];
	for(int j=1;j<=M;++j)	cin >> B[j];
	cin >> X;
	
	SumA[0]=0;
	for(int i=1;i<=N;++i)	SumA[i]=SumA[i-1]+A[i];
	SumB[0]=0;
	for(int i=1;i<=M;++i)	SumB[i]=SumB[i-1]+B[i];
	
	for(int l=1;l<=M;++l){
		for(int r=l, s;r<=M;++r){
			s=SumB[r]-SumB[l-1];
			LenB[s]=max(LenB[s], (r-l+1));
		}
	}
	
	for(int i=1;i<=SumB[M];++i)	LenB[i]=max(LenB[i], LenB[i-1]);
	
	int Ans=0;
	
	for(int l=1;l<=N;++l){
		for(int r=l, s;r<=N;++r){
			s=SumA[r]-SumA[l-1];
			Ans=max(Ans, (r-l+1)*LenB[min(SumB[M], X/s)]);
		}
	}
	
	cout << Ans << endl;
	
	return 0;
}
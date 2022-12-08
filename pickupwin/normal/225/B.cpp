#include <iostream>

using namespace std;

long long S, N;
int L, K;

long long F[1111111];
long long Sum[1111111];
long long ANS[1111111];
int Acnt=0;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> S >> K;
	
	Sum[0]=0LL;
	F[1]=1LL;Sum[1]=F[1];
	for(int i=2;;++i){
		F[i]=Sum[i-1]-Sum[max(0, i-K-1)];
		Sum[i]=Sum[i-1]+F[i];
		if(F[i]>S){
			L=i;
			break;
		}
	}
	
	for(int i=L;i>=1;--i){
		if(S>=F[i]){
			ANS[++Acnt]=F[i];
			S-=F[i];
		}
	}
	
	while(Acnt<2)	ANS[++Acnt]=0;
	
	cout << Acnt << endl;
	for(int i=1;i<=Acnt;++i)	cout << ANS[i] << " ";
	cout << endl;
	
	return 0;
}
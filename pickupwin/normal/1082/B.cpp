#include <iostream>
#include <string>

using namespace std;

int unCode(char c){
	return c=='G';
}

const int MAXN=100111;

string input;
int N;
int A[MAXN];
int Cnt[MAXN];

bool Test(int l, int r){
	if(Cnt[r]-Cnt[l-1]==(r-l+1))	return true;
	if(Cnt[r]-Cnt[l-1]==r-l)
		return Cnt[N]-Cnt[r]+Cnt[l-1];
	return false;
}

int main(){
	
	cin >> N;
	cin >> input;
	for(int i=1;i<=N;++i)	A[i]=unCode(input[i-1]);
	
	Cnt[0]=0;
	for(int i=1;i<=N;++i)	Cnt[i]=Cnt[i-1]+A[i];
	
	if(!Cnt[N]){
		cout << "0" << endl;
		return 0;
	}
	
	int Ans=0;
	for(int l=1, r=0;l<=N;++l){
		while(r<N && Test(l, r+1))	++r;
		Ans=max(Ans, r-l+1);
	}
	
	cout << Ans << endl;
	
	return 0;
}
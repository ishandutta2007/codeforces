#include <iostream>

using namespace std;

const int MAXL=17;

long long N;
int Num[MAXL], L=0;
int Ans=0;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	while(N%10LL==9LL){
		Ans+=9;
		N/=10LL;
	}
	
	if(N<10LL){
		Ans+=(int)(N);
		cout << Ans << endl;
		//cout << N << endl;
		return 0;
	}
	
	while(N>0LL){
		Num[++L]=(int)(N%10LL);
		N/=10LL;
	}
	
	for(int i=1;i<L;++i)	Ans+=(10+Num[i]-1);
	Ans+=(Num[L]-1);
	++Ans;
	
	cout << Ans << endl;
	
	return 0;
}
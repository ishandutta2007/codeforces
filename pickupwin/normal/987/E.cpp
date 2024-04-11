#include <iostream>
#include <string>

using namespace std;

const int MAXN=1001111;

int N;
int Num[MAXN];
int C[MAXN];
string Name[2]={"Petr", "Um_nik"};

long long ANS=0LL;

int lowbit(int k){
	return k&(-k);
}

void Add(int v){
	for(int i=v;i<=N;i+=lowbit(i))
		++C[i];
}

int Calc(int v){
	int ret=0;
	for(int i=v;i>0;i-=lowbit(i))
		ret+=C[i];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i)
		cin >> Num[i];
	
	for(int i=N;i>=1;--i){
		ANS+=Calc(Num[i]-1);
		Add(Num[i]);
	}
	
	ANS&=1;N&=1;ANS^=N;
	cout << Name[ANS] << endl;
	//cout << ANS << endl;
	
	return 0;
}
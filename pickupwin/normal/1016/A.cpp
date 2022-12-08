#include <iostream>

using namespace std;

const int MAXN=200111;

int N;
long long M;
long long Num[MAXN], Sum[MAXN];

long long C[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	cin >> M;
	for(int i=1;i<=N;++i)	cin >> Num[i];
	
	Sum[1]=Num[1];
	for(int i=2;i<=N;++i)	Sum[i]=Sum[i-1]+Num[i];
	
	for(int i=1;i<=N;++i)
		C[i]=Sum[i]/M;
	
	C[0]=0LL;
	for(int i=1, p=0;i<=N;++i, ++p){
		cout << C[i]-C[i-1] << " ";
	}
	cout << endl;
	
	return 0;
}
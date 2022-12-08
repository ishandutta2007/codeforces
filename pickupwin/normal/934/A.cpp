#include <iostream>

using namespace std;

const long long LONF=4567891012345678910LL;
const int MAXN=55;

int N, M;
long long Ns[MAXN], Ms[MAXN];
int Hid;
long long ANS=LONF;

long long Calc(){
	long long ret=-LONF;
	for(int i=1;i<=N;++i){
		if(i==Hid)	continue;
		for(int j=1;j<=M;++j)	ret=max(ret, Ns[i]*Ms[j]);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	for(int i=1;i<=N;++i)	cin >> Ns[i];
	for(int j=1;j<=M;++j)	cin >> Ms[j];
	
	for(Hid=1;Hid<=N;++Hid){
		ANS=min(ANS, Calc());
	}
	
	cout << ANS << endl;
	
	return 0;
}
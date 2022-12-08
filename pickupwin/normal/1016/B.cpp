#include <iostream>
#include <string>

using namespace std;

const int MAXN=1011;
const int MAXM=1011;
const int MAXQ=100111;

string input;
int N, M, Q;
int Num[MAXN], Test[MAXM];
int Cnt[MAXN], Sum[MAXN];

bool T(int at){
	if(at+M-1>N)	return false;
	bool ret=true;
	for(int i=at, j=1;j<=M;++i, ++j)
		if(Num[i]!=Test[j]){
			ret=false;
			break;
		}
	//if(ret)	cout << "!" << at << endl;
	return ret;
}

int L, R;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> Q;
	
	cin >> input;
	for(int i=1;i<=N;++i)
		Num[i]=input[i-1]-'a';
	cin >> input;
	for(int i=1;i<=M;++i)
		Test[i]=input[i-1]-'a';
	
	for(int i=1;i<=N;++i)
		if(T(i))	++Cnt[i];
	
	Sum[0]=0;
	for(int i=1;i<=N;++i)	Sum[i]=Sum[i-1]+Cnt[i];
	
	while(Q--){
		cin >> L >> R;
		R=R-M+1;
		if(L>R)	cout << "0" << endl;
		else	cout << Sum[R]-Sum[L-1] << endl;
	}
	
	return 0;
}
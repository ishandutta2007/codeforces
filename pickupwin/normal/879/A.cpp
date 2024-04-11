#include <iostream>
using namespace std;
int N;
int S, D, at=0;
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=1;i<=N;++i){
		cin >> S >> D;
		if(at<S)	at=S;
		else	at=((at-S)/D+1)*D+S;
	}
	cout << at << endl;
	return 0;
}
#include <iostream>
using namespace std;
int N, A, B;
bool Win=false;
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> A >> B;
	for(int i=0;i*A<=N;++i){
		if((N-i*A)%B==0){
			Win=true;
			cout << "YES" << endl;
			cout << i << " " << (N-i*A)/B << endl;
			break;
		}
	}
	if(!Win)	cout << "NO" << endl;
	return 0;
}
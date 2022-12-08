#include <iostream>

using namespace std;

int N;
int Ans[14]={0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341, 390};

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	if(N<=13)	cout << Ans[N] << endl;
	else	cout << (long long)(N-13)*49LL+(long long)(Ans[13]) << endl;
	
	return 0;
}
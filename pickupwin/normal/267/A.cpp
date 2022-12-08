#include <iostream>

using namespace std;

int N;
long long A, B;

long long Calc(long long a, long long b){
	if(b==0)	return 0LL;
	long long ret=a/b;
	ret+=Calc(b, a%b);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	while(N--){
		cin >> A >> B;
		cout << Calc(A, B) << endl;
	}
	
	return 0;
}
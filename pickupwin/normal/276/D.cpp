#include <iostream>

using namespace std;

long long L, R;
long long ANS=0LL;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> L >> R;
	
	long long l, r;
	
	for(int i=60;i>=0;--i){
		l=((L>>i)&1LL);r=((R>>i)&1LL);
		if(l!=r){
			ANS+=(1LL<<(i+1))-1LL;
			break;
		}
		//else if(l!=0){
		//	ANS+=(1LL<<i);
		//}
	}
	
	cout << ANS << endl;
	
	return 0;
}
#include <iostream>

using namespace std;

int N;
int Cnt=0;
int ANS=0;

int calc(int k){
	int ret=0;
	while(k>0){
		ret+=k%10;
		k/=10;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	for(int i=1;i<=1034567890;++i){
		if(calc(i)==10){
			++Cnt;
			if(Cnt==N)
				ANS=i;
		}
		if(ANS>0)	break;
	}
	
	cout << ANS << endl;
	
	return 0;
}
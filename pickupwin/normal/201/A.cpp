#include <iostream>

using namespace std;

int Need;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> Need;
	if(Need==3){
		cout << "5" << endl;
		return 0;	
	}
	for(int i=1;;i+=2){
		if(((i*i+1)>>1)>=Need){
			cout << i << endl;
			break;
		}
	}
	
	return 0;
}
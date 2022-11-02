#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int a,boz,b,ta,tb,ts;
	cin>>a>>b;
	ta=0;
	tb=0;
	ts=0;
	for (int i=1; i<=6; i++){
		if (abs(a-i)<abs(b-i)){
			ta+=1;
		}
		if (abs(a-i)>abs(b-i)){
			tb+=1;
		}
		if (abs(a-i)==abs(b-i)){
			ts+=1;
		}		
	}
	cout<<ta<<' '<<ts<<' '<<tb;
}
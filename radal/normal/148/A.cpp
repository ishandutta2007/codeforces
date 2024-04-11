#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int k,l,m,n,t=0;
	int d;
	cin>>k>>l>>m>>n>>d;
	for (int i=1; i<=d; i++){
		if (i%k == 0){
			t++;
			continue;
		}
		if (i%l == 0){
			t++;
			continue;
		}
		if (i%m == 0){
			t++;
			continue;
		}
		
		if (i%n == 0){
			t++;
			continue;
		}
	}
	cout<<t;
}
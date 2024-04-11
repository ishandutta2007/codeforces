#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for (int i=n+1; i<=100000; i++){
		int y,d,s,h;
		y=i%10;
		d=i%100/10;
		s=i%1000/100;
		h=i/1000;
		if (y!=d && y!=s && y!=h && d!=s && d!=h && s!=h){
			cout<<i;
			return 0;
		}
	}
}
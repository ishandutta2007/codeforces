#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int t;
	cin>>t;
	int j[t];
	for (int i=0; i<t; i++){
		int x,tt=1;
		cin>>x;
		while (x>7){
			x-=7;
			tt+=1;
		}
		j[i]=tt;
		//cout<<tt<<endl;
	}
	for (int i=0; i<t; i++){
		cout<<j[i]<<endl;
	}
}
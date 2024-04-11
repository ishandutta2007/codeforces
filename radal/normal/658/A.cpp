#include <iostream>
#include <cmath>

using namespace std;
int main(){
	int n,c,m1=0,m2=0,x1=0,x2=0;
	cin>>n>>c;
	int p[n],t[n];
	for (int i=0; i<n; i++){
		cin>>p[i];	
	}
	for (int i=0; i<n; i++){
		cin>>t[i];	
	}
	for (int i=0; i<n; i++){
		x1+=t[i];
		x2+=t[n-i-1];
		m1+=max(0,p[i]-c*x1);
		m2+=max(0,p[n-1-i]-c*x2);
	}
	if (m1>m2){
		cout<<"Limak";
	}
	if (m1 == m2){
		cout<<"Tie";
	}
	if (m2>m1){
		cout<<"Radewoosh";
	}
}
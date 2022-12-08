#include <iostream>

using namespace std;

int A, B;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> A >> B;	
	
	if(A==2 && B==3){
		cout << "<" << endl;
		return 0;
	}
	if(A==3 && B==2){
		cout << ">"	 << endl;
		return 0;
	}
	
	if((A==4 && B==2) || (A==2 && B==4) || A==B){
		cout << "=" << endl;
		return 0;
	}
	
	if(A==1){
		cout << "<" << endl;return 0;
	}
	if(B==1){
		cout << ">" << endl;return 0;
	}
	
	if(B<A)	cout << "<" << endl;
	else	cout << ">" << endl;
	
	return 0;
}
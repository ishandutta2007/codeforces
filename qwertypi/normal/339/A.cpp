#include <iostream>
#include <algorithm>
using namespace std;

char A[100];
int pos = 0;
int main(){
	char c = getchar();
	while(c != '\0' && c != '\n'){
		if(c != '+'){
			A[pos++] = c;
		}
	    c = getchar(); 
	}
	sort(A, A+pos);
	for(int i=0;i<pos-1;i++){
		cout << A[i] << '+';
	}
	cout << A[pos-1];
	return 0;
}
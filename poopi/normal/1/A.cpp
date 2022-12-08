#include<iostream>
using namespace std;

long long a, b, c;
int main(){
	cin >> a >> b >> c;
	cout << ((a + c - 1) / c) * ((b + c - 1) / c) << endl;
}
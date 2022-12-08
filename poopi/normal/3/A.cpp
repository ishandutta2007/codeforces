								/* in the name of Allah */
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;

string col(int x){
	if(x < 0)
		return "L";
	if(x > 0)
		return "R";
	return "";
}

string row(int x){
	if(x < 0)
		return "D";
	if(x > 0)
		return "U";
	return "";
}

int main(){
	char ch[4];
	for(int i = 0; i < 4; i++)
		cin >> ch[i];
	int a1 = ch[0] - 'a';
	int a2 = ch[1] - '1';
	int b1 = ch[2] - 'a';
	int b2 = ch[3] - '1';
	int n = max(abs(a1 - b1), abs(a2 - b2));
	cout << n << endl;
	for(int i = 0; i < n; i++){
		cout << col(b1 - a1) << row(b2 - a2) << endl;
		if(b1 > a1) a1++;
		else if(b1 < a1) a1--;
		if(b2 > a2) a2++;
		else if(b2 < a2) a2--;
	}
	return 0;
}
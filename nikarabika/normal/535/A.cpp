#include <bits/stdc++.h>

using namespace std;

string X[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string Y[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string Z[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if(n < 10)
		cout << Z[n] << endl;
	else if(n < 20)
		cout << X[n - 10] << endl;
	else if(n % 10 == 0)
		cout << Y[n / 10] << endl;
	else
		cout << Y[n / 10] << '-' << Z[n % 10] << endl;
	return 0;
}
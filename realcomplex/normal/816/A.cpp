#include <bits/stdc++.h>

using namespace std;

string its(int s){
	string num;
	while(s > 0){
		num += char((s % 10) + 48);
		s /= 10;
	}
	reverse(num.begin(),num.end());
	return num;
}

string iclock(int sk){
	int h = sk / 60;
	int min = sk % 60;
	string current = its(h);
	if(h < 10){
		current = "0" + current;
	}
	if(h == 0){
		current += "0";
	}
	if(min < 10){
		current += "0";
	}
	if(min == 0){
		current += "0";
	}
	current += its(min);
	return current;
}

int main() {
	int hh,min;
	char l;
	cin >> hh >> l >> min;
	int code = (hh * 60) + min;
	int i = 0;
	string val;
	while(1){
		val = iclock(code);
		if(val == string(val.rbegin(),val.rend())){
			break;
		}
		code++;
		code %= 1440;
		i++;
	}
	cout << i;
	return 0;
}
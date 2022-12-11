#include <bits/stdc++.h>
using namespace std;

bool r1(string d){
	if(d[0] < 91){
		return false;
	}
	for(int i = 1;i<d.size();i++){
		if(d[i] > 91){
			return false;
		}
	}
	return true;
}
bool r2(string d){
	for(int i = 0;i<d.size();i++){
		if(d[i] > 91){
			return false;
		}
	}
	return true;
}

int main() {
	string d;
	cin >> d;
	if(r1(d) == true || r2(d) == true){
		if(r1(d) == true){
			if(d[0] > 91){
				d[0] -= 32;
			}
			for(int i = 1;i<d.size();i++){
				if(d[i] < 91){
					d[i] += 32;
				}
			}
		}
		else{
			for(int i = 0;i<d.size();i++){
				if(d[i] < 91){
					d[i] += 32;
				}
			}
		}
		cout << d;
	}
	else{
		cout << d;
	}
	return 0;
}
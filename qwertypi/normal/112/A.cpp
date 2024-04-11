#include <iostream>

using namespace std;

string to_lower(string a){
	string s;
	for(auto i:a){
		if(i < 'a'){
			i ^= 32;
		}
		s.push_back(i);
	}
	return s;
}

int main(){
	string a, b;
	cin >> a >> b;
	a = to_lower(a);
	b = to_lower(b);
	bool End = false;
	for(int i=0;i<(int)min(a.size(), b.size());i++){
		if(a[i] > b[i]){
			cout << 1;
			End = true;
			break;
		}
		if(b[i] > a[i]){
			cout << -1;
			End = true;
			break;
		}
	}
	if(!End){
		if(a.size() > b.size()){
			cout << 1;
		}else if(a.size() == b.size()){
			cout << 0;
		}else{
			cout << -1;
		}
	}
	return 0;
}
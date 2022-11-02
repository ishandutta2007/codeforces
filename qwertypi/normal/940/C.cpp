#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

string f(string s, set<char> alpha){
	int pos = s.size()-1;
	while(pos >= 0){
		if(s[pos] == *(--alpha.end())){
			s[pos] = *alpha.begin();
			pos--; 
		}else{
			s[pos] = *(++alpha.find(s[pos]));
			break;
		}
	}
	const char * st = &(*(alpha.begin()));
	if(pos == -1){
		s.insert(0, st);
	}
	return s;
}

int main(){
	int n, r;
	cin >> n >> r;
	string s;
	cin >> s;
	set<char> alpha;
	for(auto i:s){
		alpha.insert(i);
	}
	if(n >= r){
		cout << f(s.substr(0, r), alpha);
	}else{
		cout << s;
		for(int i=0;i<r-n;i++){
			cout << *alpha.begin();
		}
	}
}
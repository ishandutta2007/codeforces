#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())
#define PB push_back
#define all(x) x.begin(), x.end()

string s, emp;
vector<string> vec[2];

bool check(int st, int en){
	if(st == en)
		return false;
	if(en > st + 1 and s[st] == '0')
		return false;
	for(int i = st; i < en; i++)
		if(s[i] < '0' or s[i] > '9')
			return false;
	return true;
}

int Find(int st, int en){
	for(int i = st; i < en; i++)
		if(s[i] == ',' or s[i] == ';')
			return i;
	return en;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	auto it = s.begin();
	while(it <= s.end()){
		auto it2 = s.begin() + Find(it - s.begin(), sz(s));
		int id = it - s.begin(), id2 = it2 - s.begin();
		vec[1 - check(id, id2)].PB(s.substr(id, id2 - id));
		it = it2 + 1;
	}
	//cout << "DONE" << endl;
	for(int i = 0; i < 2; i++){
		if(!vec[i].size())
			cout << "-";
		else{
			cout << "\"";
			for(int j = 0; j < sz(vec[i]) and (j == 0 or cout << ","); j++)
				cout << vec[i][j];
			cout << "\"";
		}
		cout << endl;
	}
	return 0;
}
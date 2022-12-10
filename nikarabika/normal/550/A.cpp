#include <bits/stdc++.h>

using namespace std;

#define PB push_back

vector<int> AB, BA;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	for(int i = 0; i < s.size() - 1; i++){
		if(s[i] == 'A' and s[i + 1] == 'B')
			AB.PB(i);
		if(s[i] == 'B' and s[i + 1] == 'A')
			BA.PB(i);
	}
	for(int i = 0; i < AB.size(); i++){
		for(int j = 0; j < BA.size(); j++)
			if(AB[i] != BA[j] and AB[i] != BA[j] + 1 and AB[i] + 1 != BA[j]){
				cout << "YES" << endl;
				return 0;
			}
	}
	cout << "NO" << endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

string s;
int k;

bool pal(int b, int e){
	for(int i = 0; i <= e - b; i++)
		if(s[b + i] != s[e - i])
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s >> k;
	if(s.size() % k){
		cout << "NO" << endl;
		return 0;
	}
	k = s.size() / k;
	for(int i = 0; i + k - 1 < s.size(); i += k)
		if(!pal(i, i + k - 1)){
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	return 0;
}
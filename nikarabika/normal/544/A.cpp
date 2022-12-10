#include <bits/stdc++.h>

using namespace std;

#define PB push_back

string s;
vector<string> ans;
int a[26], k;

int main(){
	cin >> k >> s;
	for(int i = 0; i < s.size(); i++)
		if(a[s[i] - 'a'] == 0)
			a[s[i] - 'a'] = i + 1;
	sort(a, a + 26);
	int p = 0;
	while(a[p] == 0)
		p++;
	if(p + k - 1 >= 26){
		cout << "NO" << endl;
		return 0;
	}
	for(int i = p; i < p + k - 1; i++){
		if(a[i] == 0){
			cout << "NO" << endl;
			return 0;
		}
		string t = "";
		for(int j = a[i] - 1; j < a[i + 1] - 1; j++)
			t += s[j];
		ans.PB(t);
	}
	if(a[p + k - 1] == 0){
		cout << "NO" << endl;
		return 0;
	}
	string t = "";
	for(int i = a[p + k - 1] - 1; i < s.size(); i++)
		t += s[i];
	cout << "YES" << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	cout << t << endl;
	return 0;
}
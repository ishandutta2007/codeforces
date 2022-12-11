#include <iostream>

#define AB 26

using namespace std;

string a, b;
int cnt1[AB], cnt2[AB];

int main() {
	cin >> a >> b;
	int l = 0;
	for(int i = 0;a[i];i++) {
		if(b[l] && b[l] == a[i]) {
			l++;
		}
	}
	if(!b[l]) {
		cout << "automaton" << endl;
		return 0;
	}
	for(int i = 0;a[i];i++) {
		cnt1[a[i]-'a']++;
	}
	for(int j = 0;b[j];j++) {
		cnt2[b[j]-'a']++;
	}
	bool err1 = false, err2 = false;
	for(int i = 0;i < AB;i++) {
		if(cnt2[i] > cnt1[i]) {
			err1 = true;
		}
		if(cnt2[i] < cnt1[i]) {
			err2 = true;
		}
	}
	if(!err1) {
		if(!err2) {
			cout << "array" << endl;
		}else {
			cout << "both" << endl;
		}
	}else {
		cout << "need tree" << endl;
	}
	return 0;
}
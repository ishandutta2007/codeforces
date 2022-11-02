#include <bits/stdc++.h>

using namespace std;
int cnt[26];
int act[26];

void f(bool x){
	if(x){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
void sub(){
	string s, t;
	cin >> s >> t;
	fill(cnt, cnt + 26, 0);
	fill(act, act + 26, 0);
	if(s.size() > t.size()){
		f(0);
	}else{
		for(int i = 0; i < s.size(); i++){
			act[s[i] - 'a']++;
			cnt[t[i] - 'a']++;
		}
		int diff = 0;
		for(int i = 0; i < 26; i++){
			diff += abs(act[i] - cnt[i]);
		}
		if(diff == 0){
			f(1);
			return;
		}else{
			for(int i = 0; i < t.size() - s.size(); i++){
				int ori, next;
				ori = cnt[t[i] - 'a'];
				next = cnt[t[i] - 'a'] - 1;
				diff += abs(next - act[t[i] - 'a']) - abs(ori - act[t[i] - 'a']);
				cnt[t[i] - 'a'] = next;
				ori = cnt[t[i + s.size()] - 'a'];
				next = cnt[t[i + s.size()] - 'a'] + 1;
				diff += abs(next - act[t[i + s.size()] - 'a']) - abs(ori - act[t[i + s.size()] - 'a']); 
				cnt[t[i + s.size()] - 'a'] = next;
				if(diff == 0){
					f(1);
					return;
				}
			}
		}
		f(0);
	}
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		sub();
	}
}
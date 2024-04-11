#include <bits/stdc++.h>

using namespace std;

string s;
int cnt[26];
deque<int> deq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for(int i = 0; i < s.size(); i++)
		cnt[s[i] - 'a']++;
	for(int i = 0; i < 26; i++)
		if(cnt[i] & 1)
			deq.push_back(i);
	while(deq.size() > 1){
		int x = deq.front(), y = deq.back();
		cnt[y]--;
		cnt[x]++;
		deq.pop_back();
		deq.pop_front();
	}
	if(deq.size())
		s[s.size() / 2] = deq.front() + 'a';
	int p = 0;
	for(int i = 0; i < 26; i++)
		for(int k = 0; k + 2 <= cnt[i]; k += 2)
			s[p] = s[s.size() - p - 1] = i + 'a', p++;
	cout << s << endl;
	return 0;
}
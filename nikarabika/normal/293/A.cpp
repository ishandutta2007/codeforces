#include <bits/stdc++.h>

using namespace std;

int n, ans1, ans2, cnt[4];
string s, t;

void make_1(void){
	if(cnt[3]){
		cnt[3]--;
		ans1++;
	}
	else if(cnt[2]){
		cnt[2]--;
		ans1++;
	}
	else if(cnt[1])
		cnt[1]--;
	else
		cnt[0]--;
	return;
}

void make_2(void){
	if(cnt[3]){
		cnt[3]--;
		ans2++;
	}
	else if(cnt[1]){
		cnt[1]--;
		ans2++;
	}
	else if(cnt[2])
		cnt[2]--;
	else
		cnt[0]--;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> s >> t;
	for(int i = 0; i < 2 * n; i++)
		cnt[(s[i] - '0') * 2 + t[i] - '0']++;
	for(int i = 0; i < n; i++){
		make_1();
		make_2();
	}
	cout << (ans1 > ans2 ? "First" : (ans1 == ans2 ? "Draw" : "Second")) << endl;
	return 0;
}
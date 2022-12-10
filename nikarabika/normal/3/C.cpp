#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

int win[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
	{0, 3, 6}, {1, 4, 7}, {2, 5, 8},
	{0, 4, 8}, {2, 4, 6}};
char s[9];
int cnt[3];
int win1, win2;

pii get_winner(void){
	pii ret(0, 0);
	for(int i = 0; i < 8; i++){
		if(s[win[i][0]] == 'X' and s[win[i][0]] == s[win[i][1]] and s[win[i][0]] == s[win[i][2]])
			ret.L++;
		if(s[win[i][0]] == '0' and s[win[i][0]] == s[win[i][1]] and s[win[i][0]] == s[win[i][2]])
			ret.R++;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < 9; i++){
		cin >> s[i];
		if(s[i] == 'X') cnt[0]++;
		else if(s[i] == '0') cnt[1]++;
		else cnt[2]++;
	}
	if(abs(cnt[0] - cnt[1]) > 1 or cnt[1] == cnt[0] + 1){
		cout << "illegal" << endl;
		return 0;
	}
	if(cnt[2] == 9){
		cout << "first" << endl;
		return 0;
	}
	bool could = true;
	for(int i = 0; i < 9; i++)
		if((cnt[0] == cnt[1] and s[i] == '0') or (cnt[0] != cnt[1] and s[i] == 'X')){
			char temp = s[i];
			s[i] = '.';
			pii ret = get_winner();
			if(ret.L == 0 and ret.R == 0)
				could = false;
			s[i] = temp;
		}
	if(could){
		cout << "illegal" << endl;
		return 0;
	}
	pii ret = get_winner();
	if(ret.L + ret.R == 0){
		if(cnt[2] == 0)
			cout << "draw" << endl;
		else
			cout << (cnt[0] > cnt[1] ? "second" : "first") << endl;
		return 0;
	}
	if(ret.L > 0)
		cout << "the first player won" << endl;
	else
		cout << "the second player won" << endl;
	return 0;
}
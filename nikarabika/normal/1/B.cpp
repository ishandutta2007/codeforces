//sobskdrbhvk
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
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

bool isnum(char c){
	return c >= '0' and c <= '9';
}

bool typee(string &s){
	if(s[0] != 'R')
		return 1;
	int id = s.find('C');
	if(id == sz(s) or !isnum(s[id - 1]))
		return 1;
	return 0;
}

string bistoshishimal(int num){
	int maxnum = 26, dig = 1;
	num--;
	while(num >= maxnum){
		num -= maxnum;
		maxnum *= 26;
		dig++;
	}
	string ret;
	for(int i = 0; i < dig; i++){
		ret += char(num%26 + 'A');
		num /= 26;
	}
	reverse(all(ret));
	return ret;
}

int numof(string &s){
	int maxnum = 26, ret = 0;
	for(int dig = 1; dig < sz(s); dig++, maxnum *= 26)
		ret += maxnum;
	int ret2 = 0;
	for(int i = 0; i < sz(s); i++)
		ret2 = ret2 * 26 + s[i] - 'A';
	return ret + ret2 + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	while(n--){
		cin >> s;
		int ty = typee(s);
		if(ty == 0){
			int r = 0, c = 0, i = 0;
			for(i = 1; isnum(s[i]); i++)
				r = r * 10 + s[i] - '0';
			for(i++; i < sz(s); i++)
				c = c * 10 + s[i] - '0';
			cout << bistoshishimal(c) << r << '\n';
		}
		else{
			string cstr;
			int r = 0, i = 0;
			for(i = 0; !isnum(s[i]); i++)
				cstr += s[i];
			for(; i < sz(s); i++)
				r = r * 10 + s[i] - '0';
			cout << 'R' << r << 'C' << numof(cstr) << '\n';
		}
	}
	return 0;
}
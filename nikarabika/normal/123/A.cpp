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

int cnt[26];
string s;

bool isprime(int x){
	if(x <= 1)
		return false;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for(int i = 0; i < sz(s); i++)
		cnt[s[i]-'a']++;
	int pcnt = 1;
	for(int i = sz(s)/2+1; i <= sz(s); i++)
		if(isprime(i))
			pcnt++;
	int an = -1;
	for(int i = 0; i < 26; i++)
		if(cnt[i] >= sz(s) - pcnt){
			an = i, cnt[i] -= sz(s) - pcnt;
			break;
		}
	if(~an){
		cout << "YES" << endl;
		for(int i = 1; i <= sz(s); i++)
			if(i == 1 or (i > sz(s)/2 and isprime(i)))
				for(int j = 0; j < 26; j++){
					if(cnt[j]){
						cout << char('a' + j);
						cnt[j]--;
						break;
					}
				}
			else
				cout << char('a' + an);
	}
	else
		cout << "NO" << endl;
	return 0;
}
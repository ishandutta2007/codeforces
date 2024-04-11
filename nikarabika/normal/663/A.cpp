//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 1e6 + 85 - 69;
string s;
vector<int> an, go;
int nega, posi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	getline(cin, s);
	int n = 0;
	posi = 1;
	for(int i = 0; i < sz(s); i++){
		if(s[i] == '+')
			posi++;
		else if(s[i] == '-')
			nega++;
		else if(s[i] >= '0' and s[i] <= '9')
			n = (n * 10) + s[i] - '0';
	}
	if(posi - nega * n <= n and n * posi - nega >= n){
		cout << "Possible\n";
		int rem = n - posi + nega;
		while(rem > 0)
			an.PB(min(n - 1, rem)), rem -= min(rem, n - 1);
		while(rem < 0)
			go.PB(min(n - 1, -rem)), rem += min(-rem, n - 1);
		char sign = '+';
		for(int i = 0; i < sz(s); i++)
			if(s[i] == '?'){
				if(sign == '+'){
					if(sz(an)){
						cout << an.back() + 1;
						an.pop_back();
					}
					else
						cout << 1;
				}
				else{
					if(sz(go)){
						cout << go.back() + 1;
						go.pop_back();
					}
					else
						cout << 1;
				}
			}
			else{
				if(s[i] == '+')
					sign = s[i];
				else if(s[i] == '-')
					sign = s[i];
				cout << s[i];
			}
	}
	else
		cout << "Impossible\n";
	return 0;
}
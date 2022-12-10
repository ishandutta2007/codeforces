//sobskdrbhvk
//remember the flying, the bird dies ):(
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int mp[128];
	bool mk[4];
	mp['U'] = 0;
	mp['D'] = 1;
	mp['L'] = 2;
	mp['R'] = 3;
	int n;
	string s;
	int ans =0;
	cin >> n;
	cin >> s;
	for(int i = 0; i < n;){
		int ptr = i;
		memset(mk, false, 4);
		while(ptr <= n and !(mk[mp['U']] and mk[mp['D']]) and !(mk[mp['L']] and mk[mp['R']])){
			if(ptr == n){
				ptr++;
				break;
			}
			mk[mp[s[ptr]]] = true, ptr++;
		}
		ans++;
		i = ptr - 1;
	}
	cout << ans << endl;
	return 0;
}
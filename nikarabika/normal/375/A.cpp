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

int a[4] = {1, 6, 8, 9};
int cnt[10];
string s;

void find_rem(int rm){
	do{
		int r = 0;
		for(int i = 0; i < 4; i++)
			r = (r * 10 + a[i]) % 7;
		if((r + rm) % 7 == 0)
			return;
	}while(next_permutation(a, a + 4));
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for(int i = 0; i < sz(s); i++)
		cnt[s[i] - '0']++;
	cnt[1]--, cnt[6]--, cnt[8]--, cnt[9]--;
	if(cnt[0] == sz(s) - 4){
		find_rem(0);
		for(int i = 0; i < 4; i++)
			cout << a[i];
		while(cnt[0]--)
			cout << 0;
		cout << endl;
		return 0;
	}
	int rem = 0;
	for(int i = 9; i >= 0; i--){
		while(cnt[i]--){
			rem = (rem * 10 + i) % 7;
			cout << i;
		}
	}
	rem = (rem * 10000) % 7;
	find_rem(rem);
	for(int i = 0; i < 4; i++)
		cout << a[i];
	cout << endl;
	return 0;
}
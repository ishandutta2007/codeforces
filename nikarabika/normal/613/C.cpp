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
int n;
int gcd, len, oddcnt;

string make_str(void){
	for(int i = 0; i < n; i++)
		cnt[i] /= gcd;
	len /= gcd;
	string ret;
	int ptr1, ptr2;
	if(gcd & 1){
		ret.resize(len);
		ptr1 = len / 2 - 1;
		ptr2 = len / 2 + 1;
		for(int i = 0; i < n; i++)
			if(cnt[i] & 1){
				ret[len / 2] = 'a' + i;
				cnt[i]--;
			}
		for(int i = 0; i < n; i++)
			while(cnt[i])
				ret[ptr1--] = ret[ptr2++] = 'a' + i, cnt[i] -= 2;
	}
	else{
		ret.resize(len);
		int ptr = 0;
		for(int i = 0; i < n; i++)
			while(cnt[i]--)
				ret[ptr++] = 'a' + i;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> cnt[i];
		oddcnt += cnt[i] & 1;
		gcd = __gcd(gcd, cnt[i]);
		len += cnt[i];
	}
	if(oddcnt > 1){
		cout << 0 << '\n';
		for(int i = 0; i < 26; i++)
			while(cnt[i]){
				cout << char(i + 'a');
				cnt[i]--;
			}
		cout << '\n';
		return 0;
	}
	string s = make_str();
	string t = s;
	reverse(all(t));
	cout << gcd << '\n';
	if(gcd & 1){
		for(int i = 0; i < gcd; i++)
			cout << s;
	}
	else{
		for(int i = 0; i < gcd / 2; i++)
			cout << s << t;
	}
	cout << '\n';
	return 0;
}
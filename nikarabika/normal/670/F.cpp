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

string s, t;
int cnt[10];

int dignum(int x){
	int ret = 0;
	while(x)
		ret++, x/=10;
	return max(1, ret);
}

int F(int x){
	int lo = 1, hi = x + 1;
	while(hi - lo > 1){
		int mid = (lo+hi)>>1;
		if(mid + dignum(mid) > x)
			hi = mid;
		else
			lo = mid;
	}
	return lo;
}

int getty(void){
	for(int i = 1; i < sz(t); i++)
		if(t[i] != t[i - 1])
			return t[i] > t[i - 1];
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	for(auto c : s)
		cnt[c - '0']++;
	for(auto c : t)
		cnt[c - '0']--;
	{
		int nn = F(sz(s));
		while(nn)
			cnt[nn % 10]--, nn/=10;
	}
	if(t[0] == '0'){
		for(int i = 1; i < 10; i++)
			if(cnt[i]){
				cout << i;
				cnt[i]--;
				break;
			}
		for(int i = 0; i < cnt[0]; i++)
			cout << 0;
		cout << t;
		for(int i = 1; i < 10; i++)
			for(int j = 0; j < cnt[i]; j++)
				cout << i;
		cout << endl;
		return 0;
	}
	int ty = getty();
	if(ty){
		bool an = false;
		for(int i = 1; i <= t[0] - '0'; i++)
			if(cnt[i]){
				cout << i, an = true;
				cnt[i]--;
				break;
			}
		if(!an){
			cout << t;
			for(int i = 0; i < 10; i++)
				for(int j = 0; j < cnt[i]; j++)
					cout << i;
			cout << endl;
			return 0;
		}
		for(int i = 0; i <= t[0] - '0'; i++)
			for(int j = 0; j < cnt[i]; j++)
				cout << i;
		cout << t;
		for(int i = t[0] - '0' + 1; i < 10; i++)
			for(int j = 0; j < cnt[i]; j++)
				cout << i;
		cout << endl;
		return 0;
	}
	string ret1 = t;
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < cnt[i]; j++)
			ret1 += '0' + i;
	bool an = false;
	for(int i = 1; i < t[0] - '0'; i++)
		if(cnt[i]){
			cout << i;
			an = true;
			cnt[i]--;
			break;
		}
	if(!an){
		if(!cnt[t[0]-'0'])
			cout << ret1 << endl;
		else{
			string ret2;
			ret2 += t[0];
			cnt[t[0]-'0']--;
			for(int i = 0; i < cnt[0]; i++)
				ret2 += '0';
			ret2 += t;
			for(int i = t[0]-'0'; i < 10; i++)
				for(int j = 0; j < cnt[i]; j++)
					ret2 += '0' + i;
			cout << min(ret1, ret2) << endl;
		}
		return 0;
	}
	if(an){
		for(int i = 0; i < t[0] - '0'; i++)
			for(int j = 0; j < cnt[i]; j++)
				cout << i;
		cout << t;
		for(int i = t[0]-'0'; i < 10; i++)
			for(int j = 0; j < cnt[i]; j++)
				cout << i;
		cout << endl;
	}
	return 0;
}
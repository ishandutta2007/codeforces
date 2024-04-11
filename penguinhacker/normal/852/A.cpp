#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

vector<int> dec(ll x) {
	assert(x>=0);
	if (x==0)
		return {0};
	vector<int> r;
	for (; x; r.push_back(x%10), x/=10);
	reverse(r.begin(), r.end());
	return r;
}

ar<ll, 2> brute(ll x) {
	vector<int> dig=dec(x);
	int n=dig.size();
	for (int i=0; i<1<<n-1; ++i) {
		ll s=0, cur=0;
		for (int j=0; j<n; ++j) {
			cur=10*cur+dig[j];
			if (i&1<<j) {
				s+=cur;
				cur=0;
			}
		}
		s+=cur;
		ll so=s;
		int s2=0;
		for (; s; s2+=s%10, s/=10);
		if (s2<10)
			return {i, so};
	}
	return {-1, -1};
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	while(1) {
		vector<bool> add(n-1);
		ll sum=0, cur=0;
		for (int i=0; i<n-1; ++i) {
			add[i]=rng()%10;
			cur=10*cur+s[i]-'0';
			if (add[i]) {
				sum+=cur;
				cur=0;
			}
		}
		sum+=10*cur+s[n-1]-'0';
		ar<ll, 2> cand=brute(sum);
		if (cand[0]!=-1) {
			for (int i=0; i<n; ++i) {
				cout << s[i];
				if (i<n-1&&add[i])
					cout << "+";
			}
			cout << "\n";
			ll mask=cand[0], nxt=cand[1];
			vector<int> dig=dec(sum);
			for (int i=0; i<dig.size(); ++i) {
				cout << dig[i];
				if (mask&1ll<<i)
					cout << "+";
			}
			cout << "\n";
			dig=dec(nxt);
			for (int i=0; i<dig.size(); ++i) {
				cout << dig[i];
				if (i+1<dig.size())
					cout << "+";
			}
			break;
		}
	}
	return 0;
}
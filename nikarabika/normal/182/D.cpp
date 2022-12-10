#include <bits/stdc++.h>

using namespace std;

#define PB push_back

typedef long long int ll;

const int maxn = 1e5 + 10;
string s, t, d;
vector<int> v;
const int Base = 37;
ll shash[maxn], thash[maxn], dhash[maxn];
ll P[maxn];
int ans = 0;

ll Hash(int s, int e, int wh){
	if(wh == 0)
		return (s == 0) ? shash[e] : shash[e] - shash[s - 1] * P[e - s + 1];
	if(wh == 1)
		return (s == 0) ? thash[e] : thash[e] - thash[s - 1] * P[e - s + 1];
	return (s == 0) ? dhash[e] : dhash[e] - dhash[s - 1] * P[e - s + 1];
}

void setdiv(int x){
	for(int i = 1; i * i <= x; i++){
		if(x % i == 0){
			v.PB(i);
			if(x / i != i)
				v.PB(x / i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	// preprocess
	cin >> s >> t;
	d = s.substr(0, __gcd(s.size(), t.size()));
	setdiv(d.size());
	shash[0] = s[0];
	thash[0] = t[0];
	dhash[0] = d[0];
	for(int i = 1; i < s.size(); i++)
		shash[i] = shash[i - 1] * Base + s[i];
	for(int i = 1; i < t.size(); i++)
		thash[i] = thash[i - 1] * Base + t[i];
	for(int i = 1; i < d.size(); i++)
		dhash[i] = dhash[i - 1] * Base + d[i];
	
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = P[i - 1] * Base;

	// process
	for(int i = 0; i < s.size() / d.size(); i++){
		if(Hash(i * d.size(), (i + 1) * d.size() - 1, 0) != dhash[d.size() - 1]){
			cout << 0 << endl;
			return 0;
		}
	}
	for(int i = 0; i < t.size() / d.size(); i++){
		if(Hash(i * d.size(), (i + 1) * d.size() - 1, 1) != dhash[d.size() - 1]){
			cout << 0 << endl;
			return 0;
		}
	}
	for(int i = 0; i < v.size(); i++){
		int l = d.size() / v[i];
		for(int j = 1; j < v[i]; j++){
			if(Hash(j * l, (j + 1) * l - 1, 2) != Hash(0, l - 1, 2))
				goto lab;
		}
		ans ++;
lab:
		ans += 0;
	}
	cout << ans << endl;
	return 0;
}
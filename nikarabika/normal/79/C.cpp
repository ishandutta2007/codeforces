//In the name of "God"
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 1e5 + 85 - 69, maxx = 20;
LL hash[maxn], val[maxx], P[maxn];
const LL base = 257, D = 1e9 + 7;
string s, t[maxx];
int n, moj[maxn];

LL H(int s, int e){
	return (s == 0) ? hash[e] : (((hash[e] - hash[s - 1] * P[e - s + 1]) % D) + D) % D;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s;
	hash[0] = s[0];
	P[0] = 1;
	for(int i = 1; i < s.size(); i++)
		hash[i] = (hash[i - 1] * base + s[i]) % D;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % D;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t[i];
		for(int j = 0; j < t[i].size(); j++)
			val[i] = (val[i] * base + t[i][j]) % D;
	}
	for(int i = 0; i < s.size(); i++)
		moj[i] = s.size();
	for(int i = 0; i < n; i++){
		int len = t[i].size();
		for(int j = 0; j + len - 1 < s.size(); j++)
			if(H(j, j + len - 1) == val[i])
				moj[j] = min(moj[j], j + len - 1);
	}
	/*
	for(int i = 0; i < s.size(); i++)
		cout << moj[i] << ' ';
	cout << endl;
	*/
	for(int i = s.size() - 2; i >= 0; i--)
		moj[i] = min(moj[i], moj[i + 1]);
	int Max = 0, b = 0;
	for(int i = 0; i < s.size(); i++)
		if(moj[i] - i > Max)
			Max = moj[i] - i, b = i;
	cout << Max << ' ' << b << endl;
	return 0;
}
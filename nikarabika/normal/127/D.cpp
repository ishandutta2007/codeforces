#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn=1e6;
LL partial_hash[maxn];
LL base = 37;
vector <int> v;
LL P[maxn];
string s;

LL H(int s, int e){
	if(s == 0)
		return partial_hash[e];
	s--;
	return partial_hash[e] - partial_hash[s] * P[e - s];
}

bool ism(LL hsh, int sz){
	for(int i = 1; i + sz < s.size();i++)
		if(H(i, i + sz - 1) == hsh)
			return true;
	return false;
}

int main(){
	cin >> s;

	partial_hash[0]=s[0]-'a'+1;
	for(int i=1 ; i<s.size() ; i++)
		partial_hash[i]=base*partial_hash[i-1]+s[i]-'a'+1;
	
	P[0] = 1;
	for(int i = 1; i < s.size(); i++)
		P[i] = P[i - 1] * base;
	
	for(int i = 1; i < s.size() - 1; i++)
		if(H(0, i - 1) == H(s.size() - i, s.size() - 1))
			v.push_back(i);

	if(v.size() == 0 or !ism(H(0, v[0] - 1), v[0])){
		cout << "Just a legend" << endl;
		return 0;
	}
	
	int lo = 0, hi = v.size();
	while(hi - lo > 1){
		int mid = (lo + hi) / 2;
		if(ism(H(0, v[mid] - 1), v[mid]))
			lo = mid;
		else
			hi = mid;
	}
	cout << s.substr(0, v[lo]) << endl;

	return 0;
}
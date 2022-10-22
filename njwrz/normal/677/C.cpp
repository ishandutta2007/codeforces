#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<char,ll> m;
vector <char> v;
ll ans[100];
int main(){
	ll sc=1;
	for(ll i=0;i<10;i++)v.push_back(i+'0');
	for(ll i=0;i<26;i++)v.push_back(i+'A');
	for(ll i=0;i<26;i++)v.push_back(i+'a');
	v.push_back('-');v.push_back('_');
	for(ll i=0;i<64;i++){
		for(ll j=0;j<64;j++){
			for(ll k=0;k<64;k++){
				if((j&k)==i)ans[i]++;
			}
		}
	}
	for(ll i=0;i<64;i++){
		m[v[i]]=i;
	}
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		sc*=ans[m[s[i]]];
		sc%=1000000007;
	}
	cout<<sc;
	return 0;
}
#include <bits/stdc++.h>
#include<algorithm>
#define ll long long int
using namespace std;
ll a[26],b[26];
int main(){
	ll n,k,ma=0;
	string s;
	stack <char> st;
	cin >> n >> k;
	cin >> s;
	for (ll i=0; i<n; i++){
		a[int(s[i])-int('A')]++;
	}
	for (ll i=0; i<n; i++){
		ll t=0;
		b[int(s[i])-int('A')] = 1;
		for (ll j=0; j<26; j++){
			if (b[j]){
				t++;
			}
		}
		if (a[int(s[i])-int('A')] > 1){
			a[int(s[i])-int('A')]--;
			b[int(s[i])-int('A')] = 1;
		}
		else{
			b[int(s[i])-int('A')]=0;
		}
		//cout<<ma<<endl;
		ma = max(ma,t);
	}
	if (ma > k){
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO";
}
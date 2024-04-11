#include <bits/stdc++.h>
#include <string>

#define ll long long int
using namespace std;

const int N=2e5;
pair <string,long long int> a[N],b[N];

bool kam(string s,string t){
	ll mins = min(s.size(),t.size());
	for (ll i=0; i<mins; i++){
		if (int(s[i]) < int(t[i])){
			return 1;
		}
		if (int (s[i]) > int(t[i])){
			return 0;
		}
	}
	if (s.size() < t.size()){
		return 1;
	}
	else{
		return 0;
	}
}
void pairsort(long long int l, long long int r){
	long long int m=(l+r)/2;
	if (l == r-1){
		return;
	}
	pairsort(l,m);
	pairsort(m,r);
	long long int pl = l;
	long long int pr = m;
	for (int i=l; i<r; i++){
		if (pr >= r || (pl < m && (kam(a[pl].first,a[pr].first) || (a[pl].first == a[pr].first && a[pl].second < a[pr].second)))){
			b[i].first = a[pl].first;
			b[i].second = a[pl].second;
			pl++;
		}
		else{
			b[i].first = a[pr].first;
			b[i].second = a[pr].second;
			pr++;
		}
	}
	for (ll i=l; i<r; i++){
		a[i].first = b[i].first;
		a[i].second = b[i].second;
	}
}
/*
string to_string (ll n){
	string s="";
	while (n>0){
		s+=char(n%10+int('0'));
		n/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}*/
int main (){
	ll n,r=1;
	cin >> n;
	string ans[n];
	for (ll i=0; i<n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	pairsort(0,n);
	for (ll i=0; i<n; i++){
		if (i == 0 || a[i].first!= a[i-1].first){
			ans[a[i].second] = "OK";
			r = 1;
		}
		else{
			ans[a[i].second] = a[i].first+to_string(r);
			r++;
		}
	}
	for (ll i=0; i<n; i++){
		cout<<ans[i]<<endl;
	}
}
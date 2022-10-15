//============================================================================
// Name        : 544D.cpp
// Author      : Daxi the Taxi
// Version     :
// Copyright   : ALL YOUR CODE IS BELONG TO US
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

const int MAX = 200001;
int n, best = 0, extra = 0;
ll bb,
	a[MAX];
map<p, int> freq;

ll gcd(ll a, ll b){
	return b ? gcd(b, a % b) : a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++){
		cin >> bb;

		if(a[i] != 0){
			ll gcdv = gcd(bb, a[i]);
			freq[make_pair(bb / gcdv, a[i] / gcdv)]++;
		}
		else
			extra += bb == 0;
	}

	for(pair<p, int> ent : freq)
		best = max(best, ent.second);

	printf("%d\n", best + extra);
}
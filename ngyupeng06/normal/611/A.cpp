#include <bits/stdc++.h>
using namespace std;
typedef long long int li;
typedef pair<int,int> pi;
typedef pair<li,li> pl;

li n, i;
string s, s1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s >> s1;
	if (s1=="month"){
		if (n<=29) cout << 12;
		else if (n==30) cout << 11;
		else if (n==31) cout << 7;
	}
	else {
		if (n==5 || n==6) cout << 53;
		else cout << 52;
	}
}
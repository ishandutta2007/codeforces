#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const ll D = 1e9 + 7;
int a[4];

ll P(ll x, int y){
	ll ans = 1;
	for(int i = 0; i < y; i++)
		ans = (ans * x) % D;
	return ans;
}

int main(){
	string s;
	int n;
	set<char> S;
	cin >> n;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'A')
			a[0]++;
		if(s[i] == 'C')
			a[1]++;
		if(s[i] == 'G')
			a[2]++;
		if(s[i] == 'T')
			a[3]++;
	}
	sort(a, a + 4);
	reverse(a, a + 4);
	int x = 0;
	while(x < 4 and a[x] == a[0])
		x++;
	cout << P(x, s.size())<<endl;
}
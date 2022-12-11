#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

bool perfect(int u){
	int l = 0;
	while(u > 0){
		l += u%10;
		u /= 10;
	}
	return l == 10;
}

int main(){
	fastIO;
	int k;
	cin >> k;
	int p = 1;
	while(k > 0){
		if(perfect(p++))
			k--;
	}
	cout << p-1;
	return 0;
}
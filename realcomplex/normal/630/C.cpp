#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main(){

	int n;
	cin >> n;
	ll s = 1;
	ll sum = 0;
	for(int i = 0;i<n;i++){
        s*=2;
        sum+=s;
	}
	cout << sum;
    return 0;
}
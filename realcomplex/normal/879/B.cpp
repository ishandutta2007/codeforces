#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	ll d;
	cin >> n >> d;
	int l;
	cin >> l;
	int k;
	int cnt = 0;
	for(int j = 1;j<n;j++){
		cin >> k;
		if(k<l)cnt++;
		else cnt = 1,l = k;
		if(cnt==d)break;
	}
	cout << l << endl;
	return 0;
}
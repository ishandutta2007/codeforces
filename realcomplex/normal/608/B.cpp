#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 234567;
ll cntbit[MAXN][2];

ll range(int l,int r,int bit){
	if(l==0)return cntbit[r][bit];
	else return cntbit[r][bit]-cntbit[l-1][bit];
}

int main(){
	string a,b;
	cin >> a >> b;
	for(int j = 0;j<b.size();j++){
		cntbit[j][b[j]%2]++;
	}
	for(int i = 1;i<MAXN;i++){
		cntbit[i][0]+=cntbit[i-1][0];
		cntbit[i][1]+=cntbit[i-1][1];
	}
	ll ans = 0;
	int p = b.size()-a.size();
	
	for(int j = 0;j<a.size();j++){
		ans += range(j,p,!(a[j]%2));
		p++;
	}
	cout << ans;
	return 0;
}
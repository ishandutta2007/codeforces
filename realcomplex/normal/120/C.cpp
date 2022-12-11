#include <bits/stdc++.h>

using namespace std;

#define fi first 
#define se second
#define mp make_pair

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,k;	
	cin >> n >> k;
	int s;
	int ans = 0;
	for(int i = 0;i<n;i++){
		cin >> s;
		ans += max(s%k,s-(k*3));
	}
	cout << ans << endl;
	return 0;
}
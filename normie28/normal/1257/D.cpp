#include <bits/stdc++.h>
 
using namespace std;
 
const int N = int(2e5) + 99;
 
int t;
int n;
int a[N];
int m;
int p[N], s[N];
int bst[N];
 
int main() {	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int tc = 0; tc < t; ++tc){
		cin>>n;
		for(int i = 0; i <= n; ++i) bst[i] = 0;
		for(int i = 0; i < n; ++i)
			cin>>a[i];
		cin>>m;
		for(int i = 0; i < m; ++i){
			cin>>p[i]>>s[i];
			bst[s[i]] = max(bst[s[i]], p[i]);
		}
		for(int i = n - 1; i >= 0; --i)
			bst[i] = max(bst[i], bst[i + 1]);	
		
 
		int pos = 0;
		int res = 0;
		bool ok = true;
		while(pos < n){
			++res;
			int npos = pos;
			int mx = 0;
			while(true){
				mx = max(mx, a[npos]);
				if(mx > bst[npos - pos + 1]) break;
				++npos;
			}
	
			if(pos == npos){
				ok = false;
				break;
			}
			pos = npos;
		}
 
		if(!ok) res = -1;
		cout<<res<<endl;
	}
}
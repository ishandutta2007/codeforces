#include <bits/stdc++.h>
using namespace std;
void solve(){
	string a,b;
	cin>>a>>b;
	bool f=0;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			if(a[i]==b[j])f=1;
		}
	}
	if(f)puts("YES");else puts("NO");
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++)solve();
	return 0;
}
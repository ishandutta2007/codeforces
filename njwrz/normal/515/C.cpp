#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector <int> v;
int main(){
	int n;string x;cin>>n>>x;
	for(int i=0;i<n;i++){
		if(x[i]=='4'){
			v.pb(3);v.pb(2);v.pb(2);
		}else if(x[i]=='6'){
			v.pb(5);v.pb(3);
		}else if(x[i]=='8'){
			v.pb(2);v.pb(2);v.pb(2);v.pb(7);
		}else if(x[i]=='9'){
			v.pb(2);v.pb(3);v.pb(3);v.pb(7);
		}else if(x[i]>'1'){
			v.pb(x[i]-'0');
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<v.size();i++)cout<<v[i];
	return 0;
}
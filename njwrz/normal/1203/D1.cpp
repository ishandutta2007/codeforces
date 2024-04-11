#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back()
#define all(a) a.begin(),a.end()
using namespace std;
bool check(string a,string b){
	while(!a.empty()&&!b.empty()){
		if(a[0]==b[0]){
			a.erase(a.begin());b.erase(b.begin());
		}else a.erase(a.begin());
	}
	if(b.empty()){
		return 1;
	}else return 0;
}
int main(){
	string a,b,t;
	cin>>a>>b;
	int la,lb;
	la=a.size();lb=b.size();
	int ans=0;
	for(int i=0;i<la;i++){
		for(int j=i;j<la;j++){
			t=a;
			t.erase(i,j-i+1);
			if(check(t,b)){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<char> a;
vector<int> b;
int main(){
	string s;
	cin>>s;
	char last=s[0];int l=1;
	for(int i=1;i<s.size();i++){
		if(last==s[i]){
			l++;
		}else{
			a.push_back(last);b.push_back(l);
			last=s[i];l=1;
		}
	}
	a.push_back(last);b.push_back(l);
	int n=a.size();
	if(!(n&1)){
		cout<<0;return 0;
	}
	for(int i=0;i<n/2;i++){
		if(a[i]!=a[n-i-1]||b[i]+b[n-i-1]<3){
			cout<<0;return 0;
		}
	}
	if(b[n/2]<2){
		cout<<0;return 0;
	}
	cout<<b[n/2]+1;
	return 0;
}
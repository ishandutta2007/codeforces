#include <bits/stdc++.h>
using namespace std;
bool check(string a){
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			if(a[i]==a[j])return 0;
		}
	}
	return 1;
}
int a1(string a,string b){
	int re=0;
	for(int i=0;i<a.size();i++){
		re+=(a[i]==b[i]);
	}
	return re;
}
int a2(string a,string b){
	int re=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(a[i]==b[j]){
				re++;break;
			}
		}
	}
	return re;
}
int main(){
	int ans=0;
	string s[11],shu;
	int x[11],y[11];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i]>>x[i]>>y[i];
	for(int i=123;i<=9876;i++){
		string t;
		stringstream ss;
		ss<<i;
		ss>>t;
		while(t.size()<4)t="0"+t;
		if(!check(t))continue;
		bool f=1;
		for(int j=1;j<=n;j++){
			if(a1(s[j],t)!=x[j]){
				f=0;break;
			}
			if(a2(s[j],t)-a1(s[j],t)!=y[j]){
				f=0;break;
			}
		}
		if(f)ans++,shu=t;
	}
	if(ans>1)cout<<"Need more data";
	else if(ans==0){
		cout<<"Incorrect data";
	}else cout<<shu;
	return 0;
}
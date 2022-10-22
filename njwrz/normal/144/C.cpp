#include <bits/stdc++.h>
using namespace std;
int f[30],t[30];
int main(){
	int la,lb;
	string a,b;
	cin>>a>>b;
	la=a.size();
	lb=b.size();
	if(lb>la){
		cout<<0;return 0;
	}
	for(int i=0;i<lb;i++){
		f[b[i]-'a']++;
		if(a[i]!='?')t[a[i]-'a']++;
	}
	int ans=1;
	for(int i=0;i<26;i++){
		if(t[i]>f[i]){
			ans=0;break;
		}
	}
	for(int i=lb;i<la;i++){
		if(a[i]!='?'){
			t[a[i]-'a']++;
		}
		if(a[i-lb]!='?'){
			t[a[i-lb]-'a']--;
		}
		ans++;
		for(int j=0;j<26;j++){
			if(t[j]>f[j]){
				ans--;break;
			}
		}
	}
	cout<<ans;
	return 0;
}
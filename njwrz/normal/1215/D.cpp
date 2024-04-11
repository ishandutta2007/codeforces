#include <bits/stdc++.h>
using namespace std;
string s;int l;
int main(){
	cin>>l>>s;
	int s1=0,s2=0,t1=0,t2=0;
	for(int i=0;i<l/2;i++){
		if(s[i]=='?')t1++;else s1+=s[i]-'0';
	}
	for(int i=l/2;i<l;i++){
		if(s[i]=='?')t2++;else s2+=s[i]-'0';
	}
	if(t2>t1){
		swap(t1,t2);swap(s1,s2);
	}
	int t=(t1-t2)/2*9;
	if(t!=s2-s1)cout<<"Monocarp";else cout<<"Bicarp";
	return 0;
}
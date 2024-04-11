#include <bits/stdc++.h>
using namespace std;
struct node{
	int lj;char c;
}a[30];
bool cmp(node x,node y){
	return x.lj<y.lj;
}
int f[300];
int main(){
	string s;
	cin>>s;
	for(int i=0;i<26;i++)a[i].c=i+'a';
	for(int i=0;i<s.size();i++)a[s[i]-'a'].lj++;
	sort(a,a+26,cmp);
	int t,ans=26;
	cin>>t;
	for(int i=0;i<26;i++){
		if(t>=a[i].lj){
			t-=a[i].lj;
			f[a[i].c]=1;
			ans--;
		}
	}
	cout<<ans<<'\n';
	for(int i=0;i<s.size();i++){
		if(!f[s[i]])cout<<s[i];
	}
	return 0;
}
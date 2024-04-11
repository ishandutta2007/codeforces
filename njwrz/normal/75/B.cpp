#include<string.h>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
struct node{
	string str;int qm;
}ans[1001];
map<string,int> mp,f;
bool cmp(node x1,node y1){
	return x1.qm>y1.qm||(x1.qm==y1.qm&&x1.str<y1.str);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	int n,q=0;
	string x,t,a[1001];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		if(f[x]==0){
			f[x]=1;a[q++]=x;
		}
		cin>>t;
		if(t=="posted"){
			cin>>t;
			cin>>t;
			t=t.substr(0,t.size()-2);
			if(f[t]==0){
				f[t]++;a[q++]=t;
			}
			if(t==s){
				mp[x]+=15;
			}else if(x==s){
				mp[t]+=15;
			}
			cin>>t;
		}else if(t=="likes"){
			cin>>t;
			t=t.substr(0,t.size()-2);
			if(f[t]==0){
				f[t]++;a[q++]=t;
			}
			if(t==s){
				mp[x]+=5;
			}else if(x==s){
				mp[t]+=5;
			}
			cin>>t;
		}else{
			cin>>t;cin>>t;
			t=t.substr(0,t.size()-2);
			if(f[t]==0){
				f[t]++;a[q++]=t;
			}
			if(t==s){
				mp[x]+=10;
			}else if(x==s){
				mp[t]+=10;
			}
			cin>>t;
		}
	}
	int ansq=0;
	for(int i=0;i<q;i++){
		if(a[i]==s)continue;
		ans[ansq].str=a[i];ans[ansq].qm=mp[a[i]];ansq++;
	}
	sort(ans,ans+ansq,cmp);
	for(int i=0;i<ansq;i++){
		cout<<ans[i].str<<'\n';
	}
	return 0;
}
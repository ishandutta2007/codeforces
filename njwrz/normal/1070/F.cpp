#include <bits/stdc++.h>
using namespace std;
int a[400005];
vector<int> v1,v2,v3;
int main(){
	int n,ans=0,b,a,gs=0,tt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a==11){
			ans+=b;gs++;tt++;
		}else if(a==10){
			v2.push_back(b);
		}else if(a==1){
			v1.push_back(b);
		}else v3.push_back(b);
	}
	sort(v1.begin(),v1.end(),greater<int>());
	sort(v2.begin(),v2.end(),greater<int>());
	int t=min(v1.size(),v2.size());
	gs+=t*2;
	for(int i=0;i<t;i++){
		ans+=v1[i]+v2[i];
	}
	if(v1.size()>v2.size()){
		for(int i=t;i<v1.size();i++)v3.push_back(v1[i]);
	}else{
		for(int i=t;i<v2.size();i++)v3.push_back(v2[i]);
	}
	sort(v3.begin(),v3.end(),greater<int>());
	tt+=t;
	tt*=2;
	tt-=gs;
	tt=min(tt,(int)(v3.size()));
	for(int i=0;i<tt;i++){
		ans+=v3[i];
	}
	cout<<ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
string ans[3]={"Kuro","Shiro","Katie"};
int main(){
	int a[300],t[3],n,maxi=0,ans1=0,ans2=0;
	string s[3];
	cin>>n;
	for(int i=0;i<3;i++){
		cin>>s[i];
		memset(a,0,sizeof(a));
		int len=s[i].size();
		for(int j=0;j<len;j++){
			a[s[i][j]]++;
		}
		t[i]=0;
		for(int j=0;j<300;j++)t[i]=max(t[i],a[j]);
		if(t[i]==len&&n==1){
			t[i]=len-1;
		}else t[i]=min(t[i]+n,len);
		if(t[i]>maxi){
			maxi=t[i];ans1=1;ans2=i;
		}else if(t[i]==maxi){
			ans1++;
		}
	}
	if(ans1!=1){
		cout<<"Draw";
	}else{
		cout<<ans[ans2];
	}
	return 0;
}
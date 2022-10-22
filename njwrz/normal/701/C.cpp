#include <bits/stdc++.h>
using namespace std;
int t[300],a[300];
int main(){
	string s;int len;
	cin>>len;
	cin>>s;
	bool f;
	int l=0,r;
	for(int i=0;i<len;i++){
		t[s[i]]=1;
	}
	for(int i=0;i<len;i++){
		a[s[i]]++;f=1;
		for(int j=60;j<=130;j++){
			if(t[j]&&!a[j]){
				f=0;break;
			}
		}
		if(f){
			r=i;
			break;
		}
	}
	while(a[s[l]]>1)l++,a[s[l-1]]--;
	int ans=r-l+1;
	for(int i=r+1;i<len;i++){
		a[s[i]]++;
		while(a[s[l]]>1)l++,a[s[l-1]]--;
		ans=min(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
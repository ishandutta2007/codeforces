#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int n,cnt=0;
string s[2];
int ans[maxn][2];

queue<int> d[2];
int main(){
	cin>>n;
	cin>>s[0]>>s[1];
	for (int i=0;i<n;++i){
		if (s[0][i]!=s[1][i]){
			if (s[0][i]=='a'){
				d[0].push(i);
			}
			else{
				d[1].push(i);
			}
		}
		for (int j=0;j<2;++j){
			if (d[j].size()==2){
				ans[++cnt][0]=d[j].front();
				d[j].pop();
				ans[cnt][1]=d[j].front();
				d[j].pop(); 
			}
		}
	}
	if (d[0].size()+d[1].size()==1){
		cout<<-1;
		return 0;
	}
	if (d[0].size()+d[1].size()==2){
		ans[++cnt][0]=ans[cnt][1]=d[0].front();
		ans[++cnt][0]=d[0].front();
		ans[cnt][1]=d[1].front();
	}
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;++i){
		cout<<ans[i][0]+1<<" "<<ans[i][1]+1<<endl; 
	} 
}
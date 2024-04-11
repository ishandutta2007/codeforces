#include<vector>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
vector<int> a[200001];
queue<int> q1,q2;
int main(){
	int q=0,t;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			if(q2.empty()){
				cout<<"-1";return 0;
			}
			t=q2.front();q2.pop();
			a[t].push_back(i+1);
			q1.push(t);
		}else {
			if(q1.empty()){
				q2.push(q);
				a[q].push_back(i+1);
				q++;
			}else{
				t=q1.front();q1.pop();
				a[t].push_back(i+1);
				q2.push(t);
			}
		}
	}
	if(!q1.empty()){
		cout<<"-1";return 0;
	}
	cout<<q<<'\n';
	while(!q2.empty()){
		t=q2.front();q2.pop();
		cout<<a[t].size()<<' ';
		for(int i=0;i<a[t].size();i++)cout<<a[t][i]<<' ';
		cout<<'\n';
	}
	return 0;
}
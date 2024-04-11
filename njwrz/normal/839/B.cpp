#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q1,q2;
int main(){
	int n,m,x;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		q1.push(2);q1.push(2);q1.push(4);
	}
	for(int i=0;i<m;i++){
		cin>>x;q2.push(x);
	}
	while(!q1.empty()&&!q2.empty()){
		int t1=q1.top(),t2=q2.top();q1.pop();q2.pop();
		if(t2>t1){
			q2.push(t2-t1);
		}
		if(t1-t2>1){
			q1.push(t1-t2-1);
		}
	}
	if(q2.empty()){
		cout<<"YES";
	}else cout<<"NO";
	return 0;
}
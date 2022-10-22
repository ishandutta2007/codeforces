#include <bits/stdc++.h>
using namespace std;
priority_queue <int,vector<int>,greater<int> > q;
int main(){
	int n,x,l=1,t;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		q.push(x);
	}
	while(!q.empty()){
		while(q.top()<l&&q.size()>1)q.pop();
		t=q.top();q.pop();
		if(t>=l){
			l++;
		}
	}
	cout<<l-1;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
queue<int> q1,q2;
int main(){
	int ans=0,la,lb,x,g;cin>>g;
	cin>>la;
	for(int i=0;i<la;i++){
		cin>>x;q1.push(x);
	}
	cin>>lb;
	for(int i=0;i<lb;i++){
		cin>>x;q2.push(x);
	}
	while(q1.size()&&q2.size()&&ans<10000){
		int t1,t2;ans++;
		t1=q1.front();t2=q2.front();
		q1.pop();q2.pop();
		if(t1>t2){
			q1.push(t2);q1.push(t1);
		}else{
			q2.push(t1);q2.push(t2);
		}
	}
	if(ans==10000){
		cout<<-1;
	}else {
		cout<<ans<<' ';
		if(q1.empty()){
			cout<<2;
		}else cout<<1;
	}
	return 0;
}
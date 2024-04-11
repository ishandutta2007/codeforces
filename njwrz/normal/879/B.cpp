#include <bits/stdc++.h>
using namespace std;
#define ll long long
queue<int> q;
int a[501];
int main(){
	int n=0,x=0,t=0,mx=0;ll m=0;
	cin>>n>>m;
	cin>>t;mx=t;
	for(int i=1;i<n;i++){
		cin>>x;q.push(x);
		mx=max(mx,x);
	}
	if(m>=n-1){
		cout<<mx;return 0;
	}
	while(1){
		int p=q.front();
		q.pop();
		if(p>t){
			q.push(t);t=p;a[p]++;
			if(a[p]==m){
				cout<<p;return 0;
			}
		}else{
			q.push(p);a[t]++;
			if(a[t]==m){
				cout<<t;return 0;
			}
		}
	}
	return 0;
}
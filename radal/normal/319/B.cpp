#include <bits/stdc++.h>
#include <algorithm>

using namespace std;






int a[100000];
int day[100000];
int main(){
	int n,ans=0;
	cin>>n;
	stack <int> st;
	for (int i=0; i<n; i++){
		int d=1;
		cin >> a[i];
		while (!st.empty() and a[st.top()]<a[i]){
			d = max(d,day[st.top()]+1);
			st.pop();
		}
		if (!st.empty())
			day[i]=d;
		st.push(i);
		ans=max(ans,day[i]);
		//cout<<day[i];
	}
	cout<<ans;
}
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

const int N=2e5;
int main(){
	long long int t;
	stack <long long int> s;
	cin >> t;
	for (int i=0; i < t; i++){
		long long int n;
		cin >> n;
		long long int a[n];
		stack <long long int> st;
		for (int j=0; j<n; j++){
			cin >> a[j];
		}
		sort(a , a+n);
		for (int j=0; j<n; j++){
			if (st.empty() || st.top() != a[j]){
				st.push(a[j]);
			}
		}
		cout<<st.size()<<endl;
	}
}
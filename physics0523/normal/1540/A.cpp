#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
		int n;
		cin >> n;
		vector<long long> a(n);
		for(auto &nx : a){cin >> nx;}
		if(n==1){cout << "0\n";continue;}
		sort(a.begin(),a.end());
		long long res=a[n-1],del=0;
		for(long long i=0;i<n;i++){
			res+=(del-i*a[i]);
			del+=a[i];
		}
		cout << res << '\n';
  }
  return 0;
}
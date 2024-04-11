#include<bits/stdc++.h>

using namespace std;

bool asc( const long long& left, const long long& right ){
	int ca=0,cb=0;
	long long ml=left,mr=right;
	while(ml%3==0){ml/=3;ca++;}
	while(mr%3==0){mr/=3;cb++;}
	return (ca!=cb)?(ca>cb):(ml<mr);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end(),asc);
	for(int i=0;i<n;i++){
		if(i){cout << ' ';}
		cout << a[i];
	}cout << '\n';
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
	int h,m,s;
	int t1,t2;
	cin >> h >> m >> s >> t1 >> t2;
	h%=12;t1%=12;t2%=12;
	vector<pair<int,int>> hv;
	int sh=720*s;
	int mh=12*(m*60+s);
	int hh=h*3600+m*60+s;
	hv.push_back({3600*t1,1});
	hv.push_back({3600*t2,1});
	hv.push_back({sh,0});
	hv.push_back({mh,0});
	hv.push_back({hh,0});
	sort(hv.begin(),hv.end());
	for(int i=0;i<5;i++){
		if(hv[i].second+hv[(i+1)%5].second==2){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
  return 0;
}
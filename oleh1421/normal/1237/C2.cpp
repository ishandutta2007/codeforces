#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
vector<int>x1;
void solve1(vector<pair<int,int> >v){
	sort(v.begin(),v.end());
	for (int i=0;i+1<v.size();i+=2){
		cout<<v[i].second<<" "<<v[i+1].second<<endl;
	}
	if ((int)v.size()%2) x1.push_back(v.back().second);
}
vector<int>x2;
void solve2(vector<pair<pair<int,int>,int> >v){
	sort(v.begin(),v.end());
	vector<pair<int,int> >u;
	u.push_back({v[0].first.second,v[0].second});
	for (int i=1;i<v.size();i++){
		if (v[i].first.first==v[i-1].first.first) u.push_back({v[i].first.second,v[i].second});
		else {
			solve1(u);
			u.clear();
			u.push_back({v[i].first.second,v[i].second});
		}
	}
	solve1(u);
	u.clear();
	for (int i=0;i+1<x1.size();i+=2){
		cout<<x1[i]<<" "<<x1[i+1]<<endl;
	}
	if ((int)x1.size()%2) x2.push_back(x1.back());
	x1.clear();

}
vector<int>x3;
void solve3(vector<pair<pair<int,int>,pair<int,int> > >v){
	sort(v.begin(),v.end());
	vector<pair<pair<int,int>,int> >u;
	u.push_back({{v[0].first.second,v[0].second.first},v[0].second.second});
	for (int i=1;i<v.size();i++){
		if (v[i].first.first==v[i-1].first.first) u.push_back({{v[i].first.second,v[i].second.first},v[i].second.second});
		else {
			solve2(u);
			u.clear();
			u.push_back({{v[i].first.second,v[i].second.first},v[i].second.second});
		}
	}
	solve2(u);
	u.clear();
	for (int i=0;i+1<x2.size();i+=2){
		cout<<x2[i]<<" "<<x2[i+1]<<endl;
	}
	if ((int)x2.size()%2) x3.push_back(x2.back());
	x2.clear();


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
  	int n;cin>>n;
	vector<pair<pair<int,int>,pair<int,int> > >v(n);
	for (int i=0;i<n;i++) cin>>v[i].first.first>>v[i].first.second>>v[i].second.first,v[i].second.second=i+1;
	solve3(v);
	for (int i=0;i+1<x3.size();i++){
		cout<<x3[i]<<" "<<x3[i+1]<<endl;
	}
	x3.clear();
    return 0;
}
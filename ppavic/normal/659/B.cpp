#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n,m;

vector < vector < pair <int,string> > > s;
vector < pair <int,string> > v;
string name;
int curm,p;


int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0;i<=m;i++) s.push_back(v);
	for(int i = 0;i<n;i++){
		cin >> name >> curm >> p;
		s[curm].push_back( pair<int,string> (p,name));
		sort(s[curm].begin(),s[curm].end());
		reverse(s[curm].begin(),s[curm].end());
		if(s[curm].size()>3) s[curm].pop_back();
	}
	for(int i = 1;i<=m;i++){
		if(s[i].size()==2){
			cout << s[i][0].second <<" "<< s[i][1].second << endl;
			continue;
		}
		if(s[i][1].first == s[i][2].first){
			cout << "?" << endl;
			continue;
		}
		cout << s[i][0].second << " " << s[i][1].second << endl;

	}
}
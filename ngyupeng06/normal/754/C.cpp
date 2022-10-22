#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef long double ld;
typedef pair<ld,li> pdi;
typedef pair<li,li> pll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define inf 2e9

li n, m, a, b, c, d, i, j, k, l, p, q, r, t, ans, sum, cmax, cmin, dx[8]={0,1,0,-1,1,1,-1,-1}, dy[8]={1,0,-1,0,-1,1,-1,1};
string s[105], str, str1[105], s2[105], s3;
vector<set<string> > v;
set<string> s1;
set<string>::iterator it, it1, it2;
bool good, ch, vis[105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (p=0; p<t; p++){
		for (i=0; i<105; i++) vis[i]=false;
		good = false;
		cin >> n;
		for (i=0; i<n; i++){
			cin >> s[i];
			s1.insert(s[i]);
		}
		cin >> m;
		v.resize(m);
		for (i=0;i<m;i++) v[i]=s1;
		getline(cin,str);
		for (i=0; i<m; i++){
			getline(cin,str,':');
			getline(cin, str1[i]);
			for (j=0; j<str1[i].size(); j++){
				if (!isalpha(str1[i][j])&&!isdigit(str1[i][j])){
					it = v[i].find(s3);
					if (it!=v[i].end()) v[i].erase(it);
			//		cout << s3 << "\n";
					s3.clear();
				}
				else s3+=str1[i][j];
			}
			it = v[i].find(s3);
			if (it!=v[i].end()) v[i].erase(it);
			//		cout << s3 << "\n";
			s3.clear();
			s2[i]=str;
			if (str!="?"){
				if (v[i].find(str)==v[i].end()) good = true;
				if (i+1<m){
					it = v[i+1].find(str);
					if (it!=v[i+1].end()) v[i+1].erase(it);
				}
				if (i>0){
					it = v[i-1].find(str);
					if (it!=v[i-1].end()) v[i-1].erase(it);
				}
			}
		}
	//	if (good) cout << "Hi\n";
		ch = false;
		while (!ch){
			ch = true;
			for (i=0; i<m; i++){
				if (s2[i]!="?"){
					if (v[i].find(s2[i])==v[i].end()){
						good = true;
						break;
					}
				}
				if (v[i].size()==0){
					good = true;
					break;
				}
				else if (v[i].size()==1&&!vis[i]){
					ch = false;
					vis[i]=true;
					it = v[i].begin();
					str = *it;
					if (i+1<m){
						it = v[i+1].find(str);
						if (it!=v[i+1].end()) v[i+1].erase(it);
					}
					if (i>0){
						it = v[i-1].find(str);
						if (it!=v[i-1].end()) v[i-1].erase(it);
					}
					s2[i]=str;
				}
			}
		}
		if (good){
			cout << "Impossible\n";
			v.clear();
			s1.clear();
			continue;
		}
		for (i=0; i<m; i++){
			if (s2[i]=="?"){
				it = v[i].begin();
				str = *it;
				if (i+1<m){
					it = v[i+1].find(str);
					if (it!=v[i+1].end()) v[i+1].erase(it);
				}
				if (i>0){
					it = v[i-1].find(str);
					if (it!=v[i-1].end()) v[i-1].erase(it);
				}
				s2[i]=str;
			}
		}
		for (i=0; i<m; i++){
			cout << s2[i] << ":" << str1[i] << "\n";
		}
		v.clear();
		s1.clear();
	}
}
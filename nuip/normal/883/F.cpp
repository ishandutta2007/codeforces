#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back
#define ALL(c) c.begin(),c.end()
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	vector<string> anses;
	REP(i,n){
		string ss;
		cin >> s;
		reverse(ALL(s));
		bool now=true;
		REP(i,s.size()){
			if(s[i]=='u'){
				ss+="oo";
			}
			else if(i==0){
				ss+=s[i];
			}
			else if(ss[ss.size()-1]=='h' && s[i]=='k'){

			}
			else{
				ss+=s[i];
			}
		}
		anses.PB(ss);
	}
	int ans=0;
	sort(ALL(anses));
	REP(i,n){
		if(i==0 or anses[i]!=anses[i-1]){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
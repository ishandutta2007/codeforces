#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cctype>
#include<map>


using namespace std;

int n, m, k;
struct PRC_T {
  string name;
  vector<string> parm;
};
vector<PRC_T>v;
map<string, string> mp;

int main(){
  scanf("%d\n", &n);
  for (int i=0; i<n; i++) {
    string s;
    PRC_T r;
    getline(cin, s);
    int p;

    for (p=0; p<(int)s.size(); p++) {
      if (s[p]=='v' && s[p+1]=='o' && s[p+2]=='i' && s[p+3]=='d' && isspace(s[p+4])) {
	
	for (p+=4; isspace(s[p]); p++) ;

	int x=p+1;
	for (; isalnum(s[x]) || s[x]=='_'; x++) ;
	r.name=s.substr(p, x-p);
	p=x;
	break;
      }
    }

    for (; s[p]!='('; p++) ;
    for (; s[p]!=')'; ) {
      p++;
      for (; isspace(s[p]) || s[p]==','; p++) ;
      if (s[p]==')') break;
      int x=p+1;

      for (; isalnum(s[x]); x++) ;

      r.parm.push_back(s.substr(p, x-p));
      p=x;
    }

    v.push_back(r);
  }

  cin>>m;
  for (int i=0; i<m; i++) {
    string s,t;
    cin>>s>>t;
    mp[t]=s;
  }

  scanf("%d\n", &k);

  for (int i=0; i<k; i++) {
    string s;
    getline(cin, s);
    PRC_T r;
    int p=0;
    for (;isspace(s[p]); p++) ;
    int x=p+1;
    for (; isalnum(s[x]); x++) ;
    r.name=s.substr(p, x-p);
    p=x;
    for (; s[p]!='('; p++) ;
    for (;s[p]!=')';) {
      p++;
      for (; isspace(s[p]) || s[p]==','; p++)  ;
      if (s[p]==')') break;
      x=p+1;
      for (; isalnum(s[x]); x++) ;
      r.parm.push_back(mp[s.substr(p, x-p)]);
      p=x;
    }

    
    int ans=0;
    for (int j=0; j<n; j++) {
      if (v[j].name==r.name && v[j].parm.size() == r.parm.size()) {
	bool b=1;

	for (int k=0; b && k<r.parm.size(); k++) {
	  if (v[j].parm[k]!="T" && v[j].parm[k]!=r.parm[k]) b=0;
	}
	ans+=b;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
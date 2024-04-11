#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define pb push_back
#define forn(i,n) for (int i=0;i<(int)n;i++)

using namespace std;

struct item
{
	string name; item *p; item *c;
	item(string _name,item *_p) { name = _name; p = _p; }
};

typedef item *pitem;
pitem root;
pitem now;
int n;

void pwd()
{
	vector <string> res;
	pitem v = now;
	while (v) { res.pb(v->name); v = v -> p; }
	reverse(res.begin(),res.end());
	forn(i,(int)res.size()) printf("%s/",res[i].c_str());
	puts("");
}

void go(string to)
{
	if (to.empty()) return;
	if (to == "..") now = now->p; else { now->c = new item(to,now); now = now->c; }
}

void parse(string s)
{
	if (s[0] == '/') now = root;
	string togo = ""; s += '/';
	forn(i,(int)s.size())
		if (s[i] == '/') { go(togo); togo.clear(); }
		 else togo += s[i];
}

int main() {
  //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  root = now = new item("",NULL);
  scanf("%d\n",&n);
  forn(i,n)
  {
	string s; getline(cin,s);
    if (s == "pwd") pwd(); else parse(s.substr(3,(int)s.size()-3));
  }
  
  return 0;
}
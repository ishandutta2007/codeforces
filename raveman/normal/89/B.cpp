#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back


pii GETS(string name);

struct W{
	string name;
	int h,w;
	int type;
	// 1 hbox
	// 2 vbox
	int b,sp;
	vector<string> q;

	bool calc;
	ll width;
	ll height;

	W(string s){
		stringstream ss(s);
		ss>>name>>w>>h;
		type=-1;b=sp=0;
		calc=0;
	}
	W(){type=-1;b=sp=0;calc=0;}
	pii getS(){
		if(calc) return pii(width,height);
		width=height=0;
		calc=1;
		if(type==1){
			if(q.size()==0) return pii(0,0);

			width += 2 * b;
			width += sp * (q.size() - 1 );
			REP(i,q.size()){
				pii x = GETS(q[i]);
				width += x.first;
				height = max(height, x.second);
			}
			
			height += 2 * b;
		}else if(type==2){
			if(q.size()==0) return pii(0,0);

			height += 2 * b;
			height += sp * (q.size() - 1 );
			REP(i,q.size()){
				pii x = GETS(q[i]);
				height += x.second;
				width = max(width, x.first);
			}
			width += 2 * b;
			
		}else width = w, height = h;
		return pii(width,height);
	}
};

int n;

map<string,W> w;


pii GETS(string name){return w[name].getS();}


int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>n;
	string s;
	getline(cin,s);
	REP(tc,n){
		getline(cin,s);
		if(s.size()>=7 && s.substr(0,7)=="Widget "){
			s = s.substr(7);
			REP(i,s.size()) if(s[i]==',' || s[i]=='(' || s[i]==')') s[i]=' ';
			
			W wid(s);
			w[wid.name] = wid;
		}
		else if(s.size()>=5 && s.substr(0,5)=="HBox "){
			s = s.substr(5);
			stringstream ss(s);
			ss>>s;
			W wid;
			wid.name = s;
			wid.type = 1;
			w[wid.name] = wid;
		}
		else if(s.size()>=5 && s.substr(0,5)=="VBox "){
			s = s.substr(5);
			stringstream ss(s);
			ss>>s;
			W wid;
			wid.name = s;
			wid.type = 2;
			w[wid.name] = wid;
		}else{
			REP(i,s.size()) if(s[i]=='.' || s[i]=='(' || s[i]==')') s[i]=' ';
			stringstream ss(s);
			string name;
			ss>>name;
			ss>>s;
			if(s=="pack"){
				ss>>s;
				w[name].q.pb(s);
			}else if(s=="set_border"){
				int x;
				ss>>x;
				w[name].b = x;
			}else if(s=="set_spacing"){
				int x;
				ss>>x;
				w[name].sp = x;
			}
		}
	}

	vector<pair<string,pii> > res;
	for(map<string,W>::iterator it = w.begin();it!=w.end();it++){

		W x = it->second;
		pii d = x.getS();
		res.pb(make_pair(it->first,d));
	}

	SORT(res);
	REP(i,res.size()){
		cout<<res[i].first<<' '<<res[i].second.first<<' '<<res[i].second.second<<endl;
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}
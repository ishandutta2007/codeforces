#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

map<string,int> _id;
int getID(string s){
	if(_id.count(s)) return _id[s];
	int pos = _id.size();
	return _id[s]=pos;
}

char s[1111111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	scanf(" %s",s);
	int n = strlen(s);

	stack<int> st;
	vi b;
	b.pb(0);_id[""]=0;
	for(int i=0;i<n;){
		i++;
		bool end = 0;
		if(s[i]=='/') {end=1;i++;}
		string t;
		while(isalpha(s[i])) t.pb(s[i]),i++;
		int id = getID(t);
		bool end2=0;
		if(s[i]=='/') {end2=1;i++;}
		i++;

		if(end2){
			st.push(b.size());
			b.pb(id);
			b.pb(-st.top());
			st.pop();
		}else if(end){
			b.pb(-st.top());
			st.pop();
		}else{
			st.push(b.size());
			b.pb(id);
		}
	}
	cin>>n;
	string t;
	getline(cin,t);
	REP(i,n){		
		getline(cin,t);
		stringstream ss(t);
		vi v;
		bool shit = 0;
		while(ss>>t){
			if(!_id.count(t)){
				shit =1;
				break;
			}
			v.pb(_id[t]);
		}

		int res = 0;
		if(!shit){
			int currpos = 0;
			vi started;
			REP(j,b.size()){
				if(b[j]<0){
					if(started.size() && started.back() == -b[j]){
						started.pop_back();
						currpos--;
					}
				}else{
					if(v[currpos] == b[j]){
						if(currpos + 1 < v.size()){
							started.pb(j);
							currpos++;
						}else{
							res++;
						}
					}
				}
			}
		}
		cout<<res<<endl;
	}
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}
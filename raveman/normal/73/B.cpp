#pragma comment(linker, "/STACK:60777216")  

#include <algorithm>
#include <iostream>
#include <complex>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define sz(a)                   int(a.size())
#define all(a)                  (a).begin(), (a).end()
#define CL(a, b)                memset(a, b, sizeof a) 
#define FOR(i, a, b)			for (int i(a); i < (b); ++i)
#define REP(i, n)               FOR(i, 0, n)
#define UN(a)                   sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb                      push_back
#define SORT(a)                 sort(all(a))

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n,m;
int a[111111],b[111111];
char name[111111][22];
string s[111111];
map<int,int> w;

int getMax(int id){
	string NAME = s[id];
	int total =   a[id] + b[n-1];
	w.clear();
	REP(i,n-1) w[b[i]]++;
	
	int num = 0;
	REP(i,n)if(i!=id){
		if(a[i] > total || a[i]==total && s[i] < NAME) {num++;continue;}

		int can = total - a[i];

		map<int,int>::iterator it = w.lower_bound(can);
		bool f = 0;
		while(1){
			if(it!=w.end()){
				int val = it->first;
				if(a[i] + val < total || a[i] + val == total && s[i] > NAME){
					w[val]--;
					if(w[val]==0)
						w.erase(val);
					f=1;
					break;
				}
			}

			if(it==w.begin()) break;
			it--;
		}
		if(!f) num++;
	}
	return num + 1;
}

int getMin(int id){
	string NAME = s[id];
	int total =   a[id] + b[0];
	w.clear();
	FOR(i,1,n) w[b[i]]++;
	
	int num = 0;
	REP(i,n)if(i!=id){
		if(a[i] > total || a[i]==total && s[i] < NAME) {num++;continue;}

		int can = total - a[i];

		map<int,int>::iterator it = w.lower_bound(can);
		bool f = 0;
		while(it!=w.end()){
			int val = it->first;
			if(a[i] + val > total || a[i] + val == total && s[i] < NAME){
				w[val]--;
				if(w[val]==0)
					w.erase(val);
				f=1;num++;
				break;
			}
			
			it++;
		}
	}
	return num + 1;
}
int main() {
#ifdef LocalHost
        freopen("input.txt", "r", stdin);
#endif

	cin>>n;
	REP(i,n) scanf(" %s %d",name[i],a+i),s[i]=name[i];
	cin>>m;
	REP(i,m) scanf("%d",b+i);
	sort(b,b+n);
	string v;
	cin>>v;
	int id = -1;
	REP(i,n) if(s[i]==v){id=i;break;}
	cout<<getMax(id)<<' '<<getMin(id)<<endl;
	return 0;
}
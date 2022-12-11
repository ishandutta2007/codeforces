#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

bool h[16];
map<string,int> d;


int main(){
	h[31%7]=true;
	h[30%7]=true;
	h[28%7]=true;
	d["monday"]=0;
	d["tuesday"]=1;
	d["wednesday"]=2;
	d["thursday"]=3;
	d["friday"]=4;
	d["saturday"]=5;
	d["sunday"]=6;
	string s,t;
	cin>>s>>t;
	assert(d.count(s));
	assert(d.count(t));
	puts(h[(d[t]+7-d[s])%7]?"YES":"NO");
	return 0;
}
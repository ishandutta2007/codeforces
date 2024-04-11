//Author: ACChampionEric
//Verdict: Accepted

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <utility>
#include <bitset>
#include <limits>
#include <stack>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <functional>
#include <numeric>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,m,n) for(int i=m;i<=n;i++)
#define all(i,j) for(i::iterator it=j.begin;it!=j.end;it++)
using namespace std;
map<string,int> m,g;
pair<string,int> p[1005];
int n,d;
string s;
int main(){
	cin>>n;
	int res=0;
	for(int i=0;i<n;i++){
			   cin>>s>>d;
			   m[s]+=d;
			   p[i].first=s;
			   p[i].second=d;
	}
	for(int i=0;i<n;i++)if(m[p[i].first]>res){res=m[p[i].first];}
	int i;
	for(i=0;m[p[i].first]!=res||(g[p[i].first]+=p[i].second)<res;i++);
	cout<<p[i].first;
	return 0;
}
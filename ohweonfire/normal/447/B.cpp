//In the name of God

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
typedef long long ll;
string s;
int n,v[26],maxn;
int main(){
	cin>>s>>n;
	for(int i=0;i<26;i++){cin>>v[i];maxn=max(maxn,v[i]);}
	int res=0;
	for(int i=0;i<s.size();++i)res+=v[s[i]-'a']*(i+1);
	for(int i=1;i<=n;i++)res+=maxn*(i+s.size());
	cout<<res;
	//system("pause");
	return 0;
}
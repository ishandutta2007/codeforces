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
#include <complex>
#include <cassert>
#include <numeric>
#include <valarray>
#include <ctype.h> 
#define ff first
#define ss second
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,m,n) for(int i=m;i<=n;i++)
#define all(i,j) for(i::iterator it=j.begin;it!=j.end;it++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<ll> sll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef queue<pii>qpii;
typedef queue<int>qi;
typedef queue<ll>qll;

set<char>s;
int main()
{
	s.insert('A');
	s.insert('H');
	s.insert('I');
	s.insert('M');
	s.insert('O');
	s.insert('T');
	s.insert('U');
	s.insert('V');
	s.insert('W');
	s.insert('X');
	s.insert('Y');
	string ss;
	cin>>ss;
	bool f=true;
	for(int i=0;i<ss.size()/2+1;i++)if(!(ss[i]==ss[ss.size()-1-i]&&s.count(ss[i])))f=false;
	if(f)puts("YES");else puts("NO");
    return 0;
}
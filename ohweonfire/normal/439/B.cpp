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
typedef priority_queue<int> pqi;
const int maxn=100002;
ll c[maxn];int x,n;
int main(){
	scanf("%d%d",&n,&x);
	for(int i=0;i<n;i++)scanf("%I64d",&c[i]);
	sort(c,c+n);
	ll sum=0;
	for(int i=0;i<n;i++){
			if(x<1)x=1;
			sum+=c[i]*x;
			x--;
	}
	printf("%I64d\n",sum);
	return 0;
}
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
typedef long long ll;
int x[100005];
int n,d;
int main(){
	cin>>n>>d;
	ll res=0;
	for(int i=0;i<n;i++)cin>>x[i];
	for(int i=0;i<n;i++){
			int tmp=upper_bound(x,x+n,x[i]+d)-&x[i];
			//cout<<tmp<<endl;
			res=res+(tmp-1ll)*(tmp-2ll)/2;
	}
	cout<<res<<endl;
	
	//for(;;);
	
	return 0;
}
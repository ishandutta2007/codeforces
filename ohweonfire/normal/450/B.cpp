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
const ll mod=1000000007;
ll n,x,y;
ll modulo(ll val){
   			 if(val>=0)return val%mod;
   			 return (mod-(-val)%mod)%mod;
}
int main(){
	cin>>x>>y>>n;
	n=n%6;
	if(n==0)cout<<modulo(x-y);
	if(n==1)cout<<modulo(x);
	if(n==2)cout<<modulo(y);
	if(n==3)cout<<modulo(y-x);
	if(n==4)cout<<modulo(-x);
	if(n==5)cout<<modulo(-y);
	return 0;
}
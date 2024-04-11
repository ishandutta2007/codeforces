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
const int maxn=100005;
int a[maxn],n;
int p[maxn];
bool cmp(int x,int y){return a[x]<a[y];}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;p[i]=i++)scanf("%d",a+i);
	sort(p,p+n,cmp);
	int l=n,r=-1;
	for(int i=0;i<n;i++)
	{
		if(p[i]!=i)
		{
			l=min(l,i);
			r=max(r,i);
		}
	}
	if(l==n){cout<<"yes\n1 1";return 0;}
	for(int i=l;i<=r;i++)
		if(p[i]!=l+r-i){cout<<"no";return 0;}
	cout<<"yes\n"<<l+1<<' '<<r+1;
	return 0;
}
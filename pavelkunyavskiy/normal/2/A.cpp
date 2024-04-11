#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

map<string,int> pers;
int ans;
string ansame;
string names[1000];
int nv[1000];

int main()
{
  /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif*/
  int n;
  scanf("%d",&n);
  for (int i=0;i<n;i++)
  {
  	string s;
  	int a;
  	cin>>s>>a;
  	if (pers.find(s)==pers.end())
  		pers.insert(mp(s,0));
  	pers[s]+=a;
  	names[i]=s;
  	nv[i]=pers[s]; 
  }         
	int m=0;
	for (map<string,int>::iterator iter=pers.begin();iter!=pers.end();++iter)
		m=max(m,iter->second);
	for (int i=0;i<n;i++)
		if (nv[i]>=m && pers[names[i]]==m)
			{
				cout<<names[i]<<endl;
				return 0;
			}
  return 0;
}
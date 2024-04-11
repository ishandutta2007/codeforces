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

int kol[10];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  string n,m;
  getline(cin,n);
  getline(cin,m);
  sort(n.begin(),n.end());
 	for (int i=0;i<n.size();i++)
 		if (n[i]!='0')
 		{
 			swap(n[i],n[0]);
 			break;
 		}
 	if (m==n)
 		printf("OK");
 	else
 		printf("WRONG_ANSWER");
  return 0;
}
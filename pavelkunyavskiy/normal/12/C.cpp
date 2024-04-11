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

map<string,int> number;

int num(string s){
	static int cnt=0;
	if (number.count(s)==0)
		{
			number[s]=cnt;
			cnt++;
		}
	return number[s];
}

vector<int> cs;
vector<int> kol;

int cost(){
	int res=0;
	for (int i=0;i<cs.size();i++)
		res+=cs[i]*kol[i];
	return res;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n,m;
  cin>>n>>m;
	cs.resize(n);
	kol.resize(n);
	kol.assign(n,0);
	for (int i=0;i<n;i++)
		cin>>cs[i];
	sort(cs.begin(),cs.end());
	for (int i=0;i<m;i++){
		string s;
		cin>>s;
		kol[num(s)]++;
	}
	sort(kol.begin(),kol.end());
	reverse(cs.begin(),cs.end());
	cout<<cost()<<" ";
	reverse(cs.begin(),cs.end());
	cout<<cost();
  return 0;
}
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
struct bign{
	int a[102];
	int length(){
	   int ans=101;
	   while(!a[ans])ans--;
	   if(ans==0)ans=1;
	   return ans;
	}
	bool operator <(bign &b){
		 if(length()<b.length())return true;
		 else if(length()>b.length())return false;/**/
		 for(int i=101;i>=0;i--){
		 		 if(a[i]<b.a[i])return true;
		 		 if(a[i]>b.a[i])return false;
		}
		return false;
	}
};/**/
string s;
int add,res;
int main(){
	cin>>s>>add;
	for(int tmp=0;tmp<s.size();tmp++){
			string t=s.substr(tmp);
			for(int i=0;;i++){
					if(i*2>t.size()+add)break;
					bool ok=true;
					for(int j=0;j<i;j++){
							if(i+j<t.size())ok&=(t[j]==t[i+j]);
					}
					if(ok)res=max(res,i);
			}
	}
	cout<<res*2<<endl;
	//system("pause");
	return 0;
}
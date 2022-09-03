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
queue<int> even,odd;
vector<int> ans[100005];
int n,k,p;
int main(){
	scanf("%d%d%d",&n,&k,&p);
	for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			if(x&1)odd.push(x);else even.push(x);
	}
	if((odd.size()&1)!=((k-p)&1)){printf("NO");return 0;}
	if(k-p>odd.size()){printf("NO");return 0;}
	if((odd.size()-k+p)/2+even.size()<p){printf("NO");return 0;}
	printf("YES\n");
	int i=0;
	while(!odd.empty()&&i<k-p){ans[i].push_back(odd.front());if(i!=k-1)i++;odd.pop();}
	while(!even.empty()){ans[i].push_back(even.front());if(i!=k-1)i++;even.pop();}
	i=k-1;
	while(!odd.empty()){ans[i].push_back(odd.front());odd.pop();
	ans[i].push_back(odd.front());odd.pop();if(i!=0)i--;}
	for(int i=0;i<k;i++){
			printf("%d ",ans[i].size());
			for(int j=0;j<ans[i].size();j++)printf("%d ",ans[i][j]);
			printf("\n");
	}
	
	//system("pause");
	return 0;
}
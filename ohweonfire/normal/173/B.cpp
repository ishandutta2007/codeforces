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
int n,m,dist[2002];
queue<int> q;
string s[1002];
vector<int> g[2004];
int main()
{
 	cin>>n>>m;
 	for(int i=0;i<n;i++){
			cin>>s[i];
			for(int j=0;j<m;j++)if(s[i][j]=='#'){g[i].push_back(n+j);g[n+j].push_back(i);}
	}
	memset(dist,-1,sizeof(dist));
	q.push(0);
	dist[0]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)if(dist[g[u][i]]==-1){
				dist[g[u][i]]=dist[u]+1;
				q.push(g[u][i]);
		}
	}
	cout<<dist[n-1];
	return 0;
}
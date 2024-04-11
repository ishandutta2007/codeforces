//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;
int main()
{
//	ifstream cin("input.txt");
//    ofstream cout("output.txt");
	int n,m,w[500];
	long long ans=0;
	cin>>n>>m;
	vector< set<int> > q(n);
	for(int i=0;i<n;i++){
		cin>>w[i];
		}
	int a;
	set<int>::iterator it;
	for(int i=0;i<m;i++){
		cin>>a;
		a--;
		for(it=q[a].begin();it!=q[a].end();it++){
			ans+=w[*it];
			}
		q[a].clear();
		for(int j=0;j<n;j++){
			if(j!=a){
				q[j].insert(a);
				}
			}
		}
	cout<<ans;
}
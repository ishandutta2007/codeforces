//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int n,q[100000],d[100000];
void dfs(int st){
    d[st]=1;
	if(d[st+q[st]]==0){
		dfs(st+q[st]);
	}
}
int main()
{
//	ifstream cin("input.txt");
//    ofstream cout("output.txt");
	int t;
	cin>>n>>t;
	for(int i=1;i<=n-1;i++){
		cin>>q[i];
	}
	for(int i=1;i<=n;i++){
		d[i]=0;
	}
	dfs(1);
	if(d[t]==1){
		cout<<"YES";
	}
	else{
		cout<<"NO";
		}

}
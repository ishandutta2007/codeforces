// ConsoleApplication1.cpp:      .
//
//#include "stdafx.h"
//#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main()
{
//	ifstream cin("input.txt");
//    ofstream cout("output.txt");
	int n,m;
	map <string,string> sl;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s2.length()<s1.length()){
		  sl[s1]=s2;
		}
		else{
		  sl[s1]=s1;
		}
	}
	for(int i=0;i<n;i++){
	   string s;
	   cin>>s;
	   cout<<sl[s]<<" ";
	}
}
// ConsoleApplication1.cpp:      .
//
//#include "stdafx.h"
//#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
//	ifstream cin("input.txt");
//    ofstream cout("output.txt");
	int n,x,l[50],r[50];
	cin>>n>>x;
	for(int i=0;i<n;i++){
	   cin>>l[i]>>r[i];
	}
	int i=1;
	int k=0,a=0;
	while(i<=r[n-1]){
		while(i+x<=l[k]){
		     i+=x;
		}
		a+=r[k]-i+1;
		i=r[k]+1;
		k++;
	}
	cout<<a;
}
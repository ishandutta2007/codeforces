#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define forl(v )  for (int l=0; l<v; l++)
#define fori(v) for (int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
int main()
{
	lli aylar[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	lli n ,d;
	cin>>n>>d;
	lli gun = aylar[n];
	gun-=7-d+1 ;
	lli say = gun/7;
	if(say*7!=gun) ++ say;
	++say;
	cout<<say;
}
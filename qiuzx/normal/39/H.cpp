#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
int make(int x,int k)
{
	long long p=0,t=1;
	while(x!=0)
	{
		p+=(x%k)*t;
		t*=10;
		x/=k;
	}
	return p;
}
int main(){
	int k,i,j;
	cin>>k;
	for(i=1;i<k;i++)
	{
		for(j=1;j<k;j++)
		{
			cout<<make(i*j,k)<<" ";
		}
		cout<<endl;
	}
	return 0;
}
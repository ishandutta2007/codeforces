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
int main(){
	int n,i,j,ans=0,y;
	double x;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			x=sqrt(i*i+j*j);
			y=sqrt(i*i+j*j);
			if(x==y&&y>=j&&y<=n)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
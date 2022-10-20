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
long long n,dig=10,ans=0;
int main(){
	long long mk=1e9,i,j,k,l;
	vector<long long> tri,book;
	book.clear();
	cin>>n;
	while(n<mk)
	{
		mk/=10;
		dig--;
	}
	for(l=0;l<(long long)1<<dig;l++)
	{
		tri.clear();
		j=l;
		while(j!=0)
		{
			tri.push_back(j%2);
			j/=2;
		}
		reverse(tri.begin(),tri.end());
		for(i=0;i<=9;i++)
		{
			for(j=0;j<=9;j++)
			{
				mk=0;
				for(k=0;k<tri.size();k++)
				{
					if(tri[k])
					{
						mk=mk*10+i;
					}
					else
					{
						mk=mk*10+j;
					}
				}
				if(mk>0&&mk<=n&&find(book.begin(),book.end(),mk)==book.end())
				{
					ans++;
					book.push_back(mk);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
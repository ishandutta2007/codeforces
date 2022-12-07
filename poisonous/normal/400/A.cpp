#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
char s[15];
vector<int> v;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		v.clear();
		getchar();
		scanf("%s",s);
		int k=0;
		for(int p=1;p<=12;p++)
			if(12%p==0)
				for(int q=0;q<p;q++)
				{
					bool b=1;
					for(int r=0;r*p<12;r++)
						if(s[r*p+q]=='O')
							b=0;
					if(b)
					{
						k++;
						v.push_back(p);
						break;
					}
				}
		cout<<k<<' ';
		for(int p=k-1;p>=0;p--)
			cout<<12/v[p]<<'x'<<v[p]<<' ';
		cout<<endl;
	}
}
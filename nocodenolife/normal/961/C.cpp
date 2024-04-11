#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int pie= n*n;
	int ans[4]={0};
	
	for(int j=0;j<4;j++)
	{
		int change=0;
		for(int i=0;i<pie;i++)
		{
			char k=' ';
			while(k!='1'&&k!='0')
				cin>>k;
			if(i%2==0)
			{
				if(k=='0')
					change++;
			}
			else
			{
				if(k=='1')
					change++;
			}
		}
		ans[j] = change;
	}
	sort(ans, ans+4);
	
	int answer = ans[0]+ans[1];
	answer += pie*2 - ans[2] - ans[3];
	
	cout<<answer<<endl;
	
	return 0;
}
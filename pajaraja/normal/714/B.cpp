#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dif;
int a[100000];
int main(int argc, char** argv) 
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) 
	{
	    scanf("%d",&a[i]);
	    int t=a[i];
	    bool imali=false;
	    for(int j=0;j<dif.size();j++) if(t==dif[j]) imali=true;
	    if(!imali)
	    {
	    	dif.push_back(t);
	    	if(dif.size()>3) 
	    	{
	    		printf("NO");
	    		return 0;
			}
		}
	}
	if(dif.size()==2||dif.size()==1) printf("YES");
		if(dif.size()==3)
		{
			sort(dif.begin(),dif.end());
			if(dif[0]+dif[2]==2*dif[1]) printf("YES");
			else printf("NO");
		}
	return 0;
}
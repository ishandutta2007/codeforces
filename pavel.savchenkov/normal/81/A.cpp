#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	char s[200070];
	int prev[200070]; 
	int i=0; int last=0; prev[0]=-1; bool ok[200070]; 
	while (cin>>s[i])
	{
		ok[i]=true;
		if (i<1) {i++;continue;}

		if (last==-1) {last=i;prev[i]=-1;i++;continue;} 	
		 if (s[i]==s[last]) 
		  {ok[last]=false;ok[i]=false;last=prev[last];prev[i]=last;} 
		  else {prev[i]=last;last=i;}
		i++;
	}
    for (int j=0;j<i;j++) 
		if (ok[j]) printf("%c",s[j]);
	return 0;
}
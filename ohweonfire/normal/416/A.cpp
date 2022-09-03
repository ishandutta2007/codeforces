#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <utility>
#include <bitset>
#include <limits>
#include <stack>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <complex>
#include <cassert>
#include <numeric>
#include <valarray>
#include <ctype.h> 
using namespace std;
int main()
{
 	string s;
 	char y_n;
 	int n,head=2000000000,tail=-head,x;
 	cin>>n;
 	
 	while(n--)
 	{
	 		  cin>>s>>x>>y_n;
	 		  if(y_n=='N')
	 		  {
			   			  if(s==">")s="<=";
			   			  else if(s==">=")s="<";
			   			  else if(s=="<")s=">=";
			   			  else s=">";
			  }
			  if(s==">")tail=max(tail,x+1);
			  else if(s==">=")tail=max(tail,x);
			  else if(s=="<")head=min(head,x-1);
			  else head=min(head,x);
	}
	if(head<tail){puts("Impossible");return 0;}
	printf("%d",tail);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
int main() {
   int n;
   char st[20],si[20];
   scanf("%d%s",&n,st);
   int m=strlen(st);
   while(--n)
   {
   	scanf("%s",si);
   	for(int i=0;i<m;++i){
   		if(si[i]!=st[i]){
   			m=i;
   			break;
   		}
   	}
   }
   printf("%d",m);
	return 0;
}
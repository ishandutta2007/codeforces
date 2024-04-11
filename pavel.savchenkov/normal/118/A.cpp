#include <cstdio>
#include <vector>
#include <cstring> 

using namespace std;


int main() {
  char s[100];
  char g[]={'A', 'O', 'Y', 'E', 'U', 'I','a', 'o', 'y', 'e', 'u', 'i'};
  scanf("%s",&s);
  vector <bool> ok((int)strlen(s),true);
  
  for (int i=0;i<(int)strlen(s);i++)
    for (int j=0;j<=11;j++) 
		if (s[i]==g[j]) {ok[i]=false;}
		
  for (int i=0;i<(int)strlen(s);i++)
    if (s[i]<97) s[i]=s[i]+32;
  
  for (int i=0;i<(int)strlen(s);i++)
    if (ok[i]) {printf(".%c",s[i]);}	  
  return 0;	
}
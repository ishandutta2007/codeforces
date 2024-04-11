#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	char s[10]; 
	scanf("%s\n",s); int min=0;
	for (int i=0;i<(int)strlen(s);i++)
		if (s[i]<s[min]&s[i]!='0') min=i;
	char c; c=s[0]; s[0]=s[min]; s[min]=c;
		
	for (int i=1;i<strlen(s);i++)
		for (int j=i+1;j<strlen(s);j++)
			if (s[j]<s[i]) {char c; c=s[i]; s[i]=s[j]; s[j]=c;}
			
	char res[10];
	scanf("%s",res); 
    if (strcmp(res,s)==0) printf("OK"); else printf("WRONG_ANSWER");
return 0;
}
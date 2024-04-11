#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char s[200];
	scanf("%s\n",&s);
	int n;
	scanf("%d",&n);
	char res[200];res[0]='\0';
	
	for (int i=1;i<=n;i++)
	{
		char d[200];
		scanf("%s\n",&d);
		if (strlen(d)<strlen(s)) continue;
		bool ok=true;
		for (int j=0;j<(int)strlen(s);j++)
			if (s[j]!=d[j]) {ok=false;break;}
		if (!ok) continue;
		if (ok&&(strcmp(res,d))>0||strlen(res)==0) 
			strcpy(res,d);
	}
	if (strlen(res)==0) strcpy(res,s);
	printf("%s",res);
	return 0;
}
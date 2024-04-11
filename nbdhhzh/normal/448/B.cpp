#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s1[110],s2[110],gs1[30],gs2[30],i,j;
int main()
{
    scanf("%s",s1);scanf("%s",s2);
    for (i=0;i<strlen(s1);i++)gs1[s1[i]-'a']++;
    for (i=0;i<strlen(s2);i++)gs2[s2[i]-'a']++;
    if (strlen(s1)==strlen(s2))
    {for (i=0;i<26;i++)if (gs1[i]!=gs2[i])break;
    if (i>=26){printf("array\n");return 0;}}j=0;
    for (i=0;i<strlen(s2)&&j<strlen(s1);i++,j++)
        while (s2[i]!=s1[j]&&j<strlen(s1))j++;
    if (i==strlen(s2)&&j<=strlen(s1)){printf("automaton\n");return 0;}
    for (i=0;i<26;i++)if (gs1[i]<gs2[i])break;
    if (i>=26)printf("both\n");else printf("need tree\n");
}
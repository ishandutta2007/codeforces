# include <algorithm>
# include <cctype>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <iostream>
# include <set>
# include <vector>
# include <queue>

using namespace std;

char testnum[5]="0000",out[5];
char usednums[10][5];
int bull[10],cow[10];
int exist1[10],exist2[10];

void countbullscows(char *a,char *b,int &bull,int &cow)
{
    for(int i=0;i<10;i++)
        exist1[i]=exist2[i]=0;
    bull=cow=0;
    for(int i=0;i<4;i++)
    {
        exist1[a[i]-'0']++;
        exist2[b[i]-'0']++;
        if(a[i]==b[i])bull++;
    }
    for(int i=0;i<10;i++)
        cow+=min(exist1[i],exist2[i]);
    cow-=bull;
}

int main()
{
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
        scanf("%s%d%d",usednums[i],&bull[i],&cow[i]);
    
    int countcorrect=0;
    for(testnum[0]='0';testnum[0]<='9';testnum[0]++)
    for(testnum[1]='0';testnum[1]<='9';testnum[1]++)
    for(testnum[2]='0';testnum[2]<='9';testnum[2]++)
    for(testnum[3]='0';testnum[3]<='9';testnum[3]++)
    {
        if(testnum[0]==testnum[1]||testnum[0]==testnum[2]||testnum[0]==testnum[3]||testnum[2]==testnum[1]||testnum[3]==testnum[1]||testnum[2]==testnum[3])continue;
        int b,c;
        for(int i=0;i<N;i++)
        {
            countbullscows(testnum,usednums[i],b,c);
            if(b!=bull[i]||c!=cow[i])goto bpp;
        }
        countcorrect++;
        strcpy(out,testnum);
        if(countcorrect>1)
        {
            printf("Need more data\n");
            return 0;
        }
        bpp:;
    }
    if(countcorrect==0)printf("Incorrect data\n");
    else printf("%s\n",out);
    return 0;
}
# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cctype>
# include <set>
# include <map>
# include <cmath>

using namespace std;

char valid[26][26];
int bestvalid[26];
char inp[100001],bad[3];

int main()
{
    memset(valid,1,676);
    scanf("%s",inp);
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",bad);
        valid[bad[0]-'a'][bad[1]-'a']=valid[bad[1]-'a'][bad[0]-'a']=0;
    }
    
    int best=0;
    for(int i=0;inp[i];i++)
    {
        char c=inp[i]-'a';
        int ret=0;
        for(int j=0;j<26;j++)
            if(valid[c][j])ret=max(ret,bestvalid[j]);
        bestvalid[c]=max(bestvalid[c],ret+1);
        best=max(best,bestvalid[c]);
    }
    printf("%d\n",(int)strlen(inp)-best);
    return 0;
}
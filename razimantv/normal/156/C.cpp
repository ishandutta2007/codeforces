# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

const int MOD=1000000007;
int best[100][2501];
char inp[101];

int main()
{
    for(int i=0;i<26;i++)
        best[0][i]=1;
    for(int i=1;i<100;i++)
        for(int j=0;j<=2500;j++)
            for(int k=max(0,j-25);k<=j;k++)
            {
                best[i][j]+=best[i-1][k];
                if(best[i][j]>=MOD)best[i][j]-=MOD;
            }
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%s",inp);
        int L=strlen(inp),sum=0;
        for(int i=0;i<L;i++)
            sum+=inp[i]-'a';
        printf("%d\n",(best[L-1][sum]+MOD-1)%MOD);
    }
    return 0;
}
# include <cstdio>
# include <cstring>
# define MOD 1000000007

char ismatched[700][700];
int firstmatch[700];
char inp[701];
long long DP[700][700][3][3];

int main()
{
    scanf("%s",inp);
    int l=strlen(inp);
    memset(firstmatch,-1,l<<2);
    
    for(int i=0;inp[i];i++)
    {
        if(inp[i]==')')continue;
        int cnt=1;
        for(int j=i+1;inp[j];j++)
        {
            if(inp[j]==')')cnt--;
            else cnt++;
            if(cnt==0)
            {
                ismatched[i][j]=1;
                if(firstmatch[i]==-1)firstmatch[i]=j;
            }
            else if(cnt<0)break;
        }
    }
    
    for(int len=2;len<=l;len+=2)
    {
        for(int i=0;i+len<=l;i++)
        {
            int j=i+len-1;
            if(!ismatched[i][j])continue;
            if(len==2)
            {//Black,Red,Blue
                DP[i][j][0][1]=DP[i][j][0][2]=DP[i][j][1][0]=DP[i][j][2][0]=1;
            }
            else
            {
                if(firstmatch[i]==j)
                {
                    DP[i][j][0][1]=DP[i][j][0][2]=(DP[i+1][j-1][0][0]+DP[i+1][j-1][0][2]+DP[i+1][j-1][1][0]+DP[i+1][j-1][1][2]+DP[i+1][j-1][2][0]+DP[i+1][j-1][2][2])%MOD;
                    DP[i][j][1][0]=DP[i][j][2][0]=(DP[i+1][j-1][0][0]+DP[i+1][j-1][2][0]+DP[i+1][j-1][0][1]+DP[i+1][j-1][2][1]+DP[i+1][j-1][0][2]+DP[i+1][j-1][2][2])%MOD;
                }
                else
                {
                    int k=firstmatch[i];
                    DP[i][j][0][0]=(((DP[i][k][0][1]*(DP[k+1][j][0][0]+DP[k+1][j][2][0]))%MOD)<<1)%MOD;
                    DP[i][j][1][0]=DP[i][j][2][0]=(DP[i][k][1][0]*((DP[k+1][j][0][0]+DP[k+1][j][1][0]+DP[k+1][j][2][0])%MOD))%MOD;
                    DP[i][j][0][1]=DP[i][j][0][2]=((DP[i][k][0][1]*(DP[k+1][j][0][1]+DP[k+1][j][2][1]))%MOD+(DP[i][k][0][2]*(DP[k+1][j][0][1]+DP[k+1][j][1][1]))%MOD)%MOD;
                    DP[i][j][1][1]=DP[i][j][2][2]=(DP[i][k][1][0]*((DP[k+1][j][0][1]+DP[k+1][j][1][1]+DP[k+1][j][2][1])%MOD))%MOD;
                    DP[i][j][1][2]=DP[i][j][2][1]=(DP[i][k][1][0]*((DP[k+1][j][0][2]+DP[k+1][j][1][2]+DP[k+1][j][2][2])%MOD))%MOD;
                }
            }
        }
    }
    
    long long ret=0ll;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            ret+=DP[0][l-1][i][j];
    ret%=MOD;
    printf("%Ld\n",ret);
}
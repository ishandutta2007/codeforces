#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c;

double dp[107][107][107];

double wyn1, wyn2, wyn3;

double ilo;

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    dp[a][b][c]=1.0;
    for (int i=a; i>=0; i--)
    {
        for (int j=b; j>=0; j--)
        {
            for (int l=c; l>=0; l--)
            {
                if (!i && !j && !l)
                continue;
                if (!i && !j)
                {
                    wyn3+=dp[i][j][l];
                    continue;
                }
                if (!i && !l)
                {
                    wyn2+=dp[i][j][l];
                    continue;
                }
                if (!j && !l)
                {
                    wyn1+=dp[i][j][l];
                    continue;
                }
                if (!i)
                {
                    dp[i][j][l-1]+=dp[i][j][l];
                    continue;
                }
                if (!j)
                {
                    dp[i-1][j][l]+=dp[i][j][l];
                    continue;
                }
                if (!l)
                {
                    dp[i][j-1][l]+=dp[i][j][l];
                    continue;
                }
                ilo=1.0*(i*j+j*l+i*l);
                dp[i-1][j][l]+=dp[i][j][l]*(i*l)/ilo;
                dp[i][j-1][l]+=dp[i][j][l]*(i*j)/ilo;
                dp[i][j][l-1]+=dp[i][j][l]*(j*l)/ilo;
            }
        }
    }
    printf("%.10lf %.10lf %.10lf\n", wyn1, wyn2, wyn3);
    return 0;
}
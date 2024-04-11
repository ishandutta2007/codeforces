#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
char A[MAXN][MAXN],B[MAXN][MAXN];
bool C[MAXN][MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",A[i]);
        for(int i=0;i<n;i++)
            scanf("%s",B[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                C[i][j]=(A[i][j]-'0')^(B[i][j]-'0');
        for(int i=0;i<n;i++)
            for(int j=0;j+1<n;j++)
                C[i][j]^=C[i][j+1];
        bool isok=1;
        for(int i=0;i+1<n;i++)
            for(int j=0;j+1<n;j++)
                isok&=(C[i][j]==C[i+1][j]);
        printf("%s\n",(isok ? "YES" : "NO"));
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int matrix[101][101];
int num[4];
int arr[4];

void sort(int s, int e)
{
    if (e>s+1)
    {
        int m=(s+e)/2;
        sort(s, m);
        sort(m, e);
        int i=s, j=m;
        while (i<m && j<e)
        {
            if (num[i]<num[j])
            {
                arr[i+j-s-m] = num[i];
                i += 1;
            }
            else
            {
                arr[i+j-s-m] = num[j];
                j += 1;
            }
        }
        if (i==m)
        {
            for (j=j;j<e;j++)
                arr[i+j-s-m] = num[j];
        }
        else
        {
            for (i=i;i<m;i++)
                arr[i+j-s-m] = num[i];
        }
        for (int i=s;i<e;i++)
            num[i] = arr[i-s];
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++)
    {
        int n, m;
        long long ans=0;
        scanf("%d %d", &n, &m);
        for (int j=0;j<n;j++){
            for (int k=0;k<m;k++) scanf("%d", &matrix[j][k]);
        }
        int x=n/2, y=m/2;
        for (int j=0;j<x;j++){
            for (int k=0;k<y;k++){
                num[0]=matrix[j][k];
                num[1]=matrix[j][m-1-k];
                num[2]=matrix[n-1-j][k];
                num[3]=matrix[n-1-j][m-1-k];
                sort(0, 4);
                ans += abs(num[3]-num[0])+abs(num[2]-num[1]);
            }
        }
        if (2*x!=n){
            for (int k=0;k<y;k++) ans += abs(matrix[x][k]-matrix[x][m-1-k]);
        }
        if (2*y!=m){
            for (int j=0;j<x;j++) ans += abs(matrix[j][y]-matrix[n-1-j][y]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
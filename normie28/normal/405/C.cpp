#include<bits/stdc++.h>
#define end ("\n")
using namespace std;
 

 
int main()
{
    ios_base::sync_with_stdio(false);
    
    
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int sum =0 ;
    for(int i = 0;i < n;i++)
    {
        if(arr[i][i] == 1)
            sum++;
    }
    sum %= 2;
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int t;
        scanf("%d", &t);
        if(t == 1 or t == 2)
        {
            int c;
            scanf("%d", &c);
            sum++;
            sum %= 2;
        }
        else
        {
            printf("%d", sum);
        }
    }
    return 0;
}
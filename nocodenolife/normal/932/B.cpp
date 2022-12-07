#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[1000001];
    int ans[10][1000001];
    arr[0] = 0;
    for(int i=0;i<10;i++)
    {
        ans[i][0] = 0;
    }
    for(int i = 1;i<10;i++)
    {
        arr[i] = i;
        for(int j=0;j<10;j++)
        {
            ans[j][i] = ans[j][i-1];
        }
        ans[i][i] ++;
    }
    for(int i = 10;i<1000001;i++)
    {
        int num = i;
        int prev = 1;
        while(num>0)
        {
            if(num%10!=0)
                prev *= num%10;
            num/=10;
        }
        for(int j=0;j<10;j++)
        {
            ans[j][i] = ans[j][i-1];
        }
        arr[i] = arr[prev];
        ans[arr[i]][i]++;
    }
    int q;
    cin>>q;
    while(q>0)
    {
        int l,r,k;
        cin>>l>>r>>k;
        l--;
        cout<<ans[k][r] - ans[k][l]<<endl; 
        
        q--;
    }
    
    return 0;
}
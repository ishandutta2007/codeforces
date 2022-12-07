#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string k;
    cin>>k;
    char first,second;
    int max = 0;
    int dp[26][26] = {{0}};
    for(int i=0;i<n-1;i++)
    {
        char o = k[i];
        char t = k[i+1];
        int row,col;
        row =(int)o - 'A';
        col =(int) t - 'A';
        dp[row][col]++;
        if(dp[row][col]>max)
        {
            max = dp[row][col];
            first=o;
            second =t;
        }
    }
    cout<<first<<second<<endl;    
}
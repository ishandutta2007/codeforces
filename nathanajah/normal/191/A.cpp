#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;

int dp[26][26];
int i,j,k;
int n;
string s;
int depan,belakang;
int maxi;

int main()
{
    scanf("%d",&n);
    for (i=0;i<26;++i)
        for (j=0;j<26;++j)
            dp[i][j]=-1000000000;
    for (i=0;i<n;++i)
    {
        cin >> s;
        depan=s[0]-'a';
        belakang=s[s.length()-1]-'a';
        for (j=0;j<26;++j)
            dp[j][belakang]=max(dp[j][belakang],dp[j][depan]+(int)s.length());
        dp[depan][belakang]=max(dp[depan][belakang],(int)s.length());
    }
    for (i=0;i<26;++i)
        maxi=max(maxi,dp[i][i]);
    printf("%d\n",maxi);
}
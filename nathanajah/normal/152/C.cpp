#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <set>
#include <queue>
using namespace std;

int n,m;
string s[200];
int i,j;
int sudah[200][300];
long long total;
long long banyak;

int main()
{
    total=1;
    scanf("%d %d",&n,&m);
    for (i=0;i<n;i++)
        cin >> s[i];
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
            sudah[i][s[j][i]-'A']=true;
    }
    for (i=0;i<m;i++)
    {
        banyak=0;
        for (j=0;j<26;j++)
            if (sudah[i][j])
                banyak++;
        total=(total*banyak)%1000000007;
    }
    cout << total << "\n";
}
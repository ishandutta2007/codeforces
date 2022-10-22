#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N=1501;

char s[N];

int res[26][1501];

int n,q,m;

char c;

int main()
{
    cin>>n>>s>>q;
    for(int l=0;l<26;l++)
    {
        for(int i=0;i<n;i++)
         {
            int rep_c = 0;
            for(int j=i;j<n;j++)
            {
                if(s[j] - 'a' != l)
                 ++rep_c;
                res[l][rep_c] = max(res[l][rep_c] , j - i + 1);
            }
        }
        for (int i = 1 ; i <= n ; i++)
            res[l][i] = max(res[l][i] , res[l][i - 1]);
    }

    for (int i = 0 ; i < q ; i++)
    {
        cin>>m>>c;
        cout<< res[c-'a'][m]<<endl;
    }

    return 0;
}
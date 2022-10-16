#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,q;
    scanf("%i %i %i",&n,&m,&q);
    char s[n+1],t[m+1];
    scanf("%s",s);
    scanf("%s",t);
    vector<int> postoji;
    for(int i=0;i<=n-m+1;i++)
    {
        bool test=true;
        for(int j=0;j<m;j++)
        {
            if(s[i+j]!=t[j])
            {
                test=false;
            }
        }
        if(test)
        {
            //printf("Dodajem %i\n",i);
            postoji.push_back(i);
        }
    }
    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        int broj=0;
        for(int j=0;j<postoji.size();j++)
        {
            if(postoji[j]+1>=a&&postoji[j]+m<=b)
            {
                broj++;
            }
        }
        printf("%i\n",broj);
    }
    return 0;
}
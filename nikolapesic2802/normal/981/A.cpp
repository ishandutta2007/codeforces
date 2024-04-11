#include <bits/stdc++.h>

using namespace std;

int main()
{
    char niz[50];
    scanf("%s",niz);
    string s=niz;
    int n=s.length();
    int maxx=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            bool test=true;
            int mid=(i+j)/2-i;
            //printf("%i %i %i\n",i,j,mid);
            for(int k=0;k<=mid;k++)
            {
                if(niz[i+k]!=niz[j-k])
                {
                    test=false;
                }
            }
            if(!test)
            {
                maxx=max(maxx,j-i+1);
            }
        }
    }
    printf("%i\n",maxx);
    return 0;
}
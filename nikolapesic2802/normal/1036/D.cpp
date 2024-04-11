#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    queue<int> niz1;
    long long zbir1=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%i",&x);
        zbir1+=x;
        niz1.push(x);
    }
    long long zbir2=0;
    int m;
    scanf("%i",&m);
    queue<int> niz2;
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%i",&x);
        zbir2+=x;
        niz2.push(x);
    }
    if(zbir1!=zbir2)
    {
        printf("-1\n");
        return 0;
    }
    long long tren1,tren2;
    int res=0;
    while(!niz1.empty())
    {
        tren1=niz1.front();tren2=niz2.front();
        niz1.pop();niz2.pop();
        while(tren1!=tren2)
        {
            if(tren1<tren2)
            {
                tren1+=niz1.front();
                niz1.pop();
            }
            else
            {
                tren2+=niz2.front();
                niz2.pop();
            }
        }
        res++;
    }
    printf("%i\n",res);
    return 0;
}
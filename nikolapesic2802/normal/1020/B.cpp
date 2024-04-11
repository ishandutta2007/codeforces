#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int sledeci[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&sledeci[i]);
        sledeci[i]--;
    }
    for(int i=0;i<n;i++)
    {
        //printf("Krecem od %i\n",i+1);
        int visited[n]={};
        int tr=i;
        while(visited[tr]==0)
        {
            visited[tr]=1;
            tr=sledeci[tr];
            //printf("Sledeci: %i\n",tr+1);
        }
        printf("%i ",tr+1);
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int number;
    map<int,int> visited;
    int broj=0;
    visited[0]=1;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        if(visited[a]==0)
        {
            visited[a]=1;
            broj++;
        }
    }
    printf("%i",broj);
    return 0;
}
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int sum=0;
    int a[n];
    int solution[k];
    for(int i=0;i<k;i++)
    {
        solution[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    bool possible= true;
    if(sum%k!=0)
    possible=false;
    int dur=sum/k;
    
    int j=0;
    for(int i=0;i<n;)
    {
        int post=0;
        while(post<dur)
        {
            post+=a[i++];
            solution[j]++;
            
        }
        j++;
        if(post>dur)
        possible=false;
    }
    if(possible==false)
    printf("No");
    else
    {
        printf("Yes\n");
        for(int i=0;i<k;i++)
    {
        printf("%d ",solution[i]);
    }
    }
}
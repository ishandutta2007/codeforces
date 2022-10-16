#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=10;
    scanf("%i",&n);
    int niz[2*n];
    for(int i=0;i<2*n;i++)
    {
        scanf("%i",&niz[i]);
    }
    /*for(int i=0;i<n;i++)
    {
        niz[i]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        niz[i+n]=n-i;
    }*/
    /*for(int i=0;i<2*n;i++)
        {
            printf("%i ",niz[i]);
        }
        printf("\n");*/
    bool test=true;
    int cnt=0;
    while(test)
    {
        int visited[n+1]={};
        int udaljenost=0;
        int koja_strana[2*n];
        bool sortiran=true;
        for(int i=0;i<2*n;i++)
        {
            if(visited[niz[i]]==0)
            {
                koja_strana[i]=1;
                visited[niz[i]]=i+1;
                if(niz[i+1]!=niz[i])
                {
                    sortiran=false;
                }
            }
            else
            {
                koja_strana[i]=2;
                //printf("Udaljenost od %i: %i\n",niz[i],i-visited[niz[i]]);
                udaljenost+=i-visited[niz[i]];
            }
        }
        if(sortiran)
        {
            break;
        }
        //cnt++;
        int koji=-1;
        for(int i=0;i<2*n;i++)
        {
            //printf("%i ",niz[i]);
            if(koja_strana[i]==1)
            {
                if(niz[i+1]!=niz[i])
                {
                    if(koja_strana[i+1]==2)
                    {
                        koji=i;
                        break;
                    }
                }
            }
            else
            {
                if(niz[i-1]!=niz[i])
                {
                    if(koja_strana[i-1]==1)
                    {
                        koji=i;
                        break;
                    }
                }
            }
        }
        //printf("\n");
        if(koji!=-1)
        {
            cnt++;
            if(koja_strana[koji]==1)
            {
                swap(niz[koji],niz[koji+1]);
            }
            else
            {
                swap(niz[koji],niz[koji-1]);
            }
        }
        else
        {
            int gde;
            int solved_end=0;
            for(int i=2*n-1;i>0;i--)
            {
                if(niz[i]==niz[i-1])
                {
                    solved_end+=2;
                    i--;
                }
                else
                {
                    break;
                }
            }
            for(int i=0;i<2*n-2;i++)
            {
                if(niz[i]==niz[i+1]&&koja_strana[i+2]==2)
                {
                    gde=i+1;
                }
            }
            //printf("gde:%i,%i %i\n",gde,solved_end,(2*n-gde-1-solved_end));
            int sta=niz[gde];
            cnt+=2*(2*n-gde-1-solved_end);
            for(int i=gde-1;i<2*n-2-solved_end;i++)
            {
                niz[i]=niz[i+2];
            }
            niz[2*n-2-solved_end]=sta;
            niz[2*n-1-solved_end]=sta;
            //niz[2*n-2]=sta;
        }
        //printf("%i %i\n",(*it).first,(*it).second);
    }
    /*for(int i=0;i<2*n;i++)
        {
            printf("%i ",niz[i]);
        }
        printf("\n");*/
    printf("%i\n",cnt);
    return 0;
}
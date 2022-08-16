# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cctype>
# include <set>
# include <map>
# include <cmath>

using namespace std;

char conso[100001];
int smallprime[100001];
vector<int> primes[100001];
set<int> collide[100001];
int on[100001];

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    
    for(int i=2;i*i<=N;i++)
    {
        if(conso[i])continue;
        for(int j=i*i;j<=N;j+=i)
        {
            conso[j]=1;
            smallprime[j]=i;
        }
    }
    
    for(int i=2;i<=N;i++)
    {
        if(smallprime[i]==0)
        {
            primes[i].push_back(i);
        }
        else
        {
            int j=i;
            while(j%smallprime[i]==0)j/=smallprime[i];
            primes[i].push_back(smallprime[i]);
            for(int k=0;k<primes[j].size();k++)
                primes[i].push_back(primes[j][k]);
        }
    }
    
    for(int i=0;i<M;i++)
    {
        char c=0;int n;
        while(c!='+'&&c!='-')scanf("%c",&c);
        scanf("%d",&n);
        
        if(c=='+')
        {
            if(on[n])
            {
                printf("Already on\n");
            }
            else
            {
                bool flag=true;
                for(int j=0;j<primes[n].size();j++)
                    if(!collide[primes[n][j]].empty())
                    {
                        printf("Conflict with %d\n",*collide[primes[n][j]].begin());
                        flag=false;
                        break;
                    }
                if(flag)
                {
                    printf("Success\n");
                    on[n]=true;
                    for(int j=0;j<primes[n].size();j++)
                        collide[primes[n][j]].insert(n);
                }
            }
        }
        else
        {
            if(!on[n])
            {
                printf("Already off\n");
            }
            else
            {
                printf("Success\n");
                on[n]=false;
                for(int j=0;j<primes[n].size();j++)
                    collide[primes[n][j]].erase(n);
            }
        }
    }
    return 0;
}
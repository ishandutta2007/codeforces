#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
const int N=3*1e5+5;
vector<int> divider(N);
int main()
{
    for(int i=2;i<N;i++)
    {
        if(!divider[i])
        {
            for(int j=i;j<N;j+=i)
            {
                divider[j]=i;
            }
        }
    }
    int n;
    scanf("%i",&n);
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        set<int> primes;
        while(a!=1)
        {
            primes.insert(divider[a]);
            a=a/divider[a];
        }
        int br=1;
        for(auto p:primes)
        {
            br*=p;
        }
        arr.pb(br);
    }
    sort(arr.begin(),arr.end());
    vector<int> visited(N),novo;
    for(auto p:arr)
    {
        if(!visited[p])
        {
            novo.pb(p);
            for(int i=p;i<N;i+=p)
            {
                visited[i]=1;
            }
        }
    }
    arr=novo;
    n=arr.size();
    int gc=0;
    for(int i=0;i<n;i++)
    {
        gc=gcd(gc,arr[i]);
    }
    if(gc!=1)
    {
        printf("-1\n");
        return 0;
    }
    cerr << arr.size() << "\n";
    int res=min(n,10);
    while(clock()<1000)
    {
        int num=0;
        int gc=0;
        while(gc!=1&&num<res)
        {
            num++;
            gc=gcd(gc,arr[rand()%n]);
        }
        if(gc==1)
        {
            res=num;
        }
    }
    printf("%i\n",res);
    return 0;
}
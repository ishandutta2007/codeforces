#include<bits/stdc++.h>
using namespace std;
int miss[1005];
int war[1005];
long long losuj(long long a)
{
    long long res = 1;
    for(int x=1;x<=10;x++)
        res = (res*rand())%a+1;
    return res;
}
int main()
{
	srand(time(NULL) + clock());
    int a,t;
    cin>>a>>t;
    while(t--)
    {
        string d;
        cin>>d;
        int mini = 1e9 , maks = -1e9;
        for(int x=0;x<a;x++)
        {
            maks = max(maks , miss[x]);
            mini = min(mini , miss[x]);
        }
        if(maks - mini > 110)
            maks = mini + 110;
        long long sum = 0;
        for(int x=0;x<a;x++)
        {
            if(miss[x] > maks)
                war[x] = 0;
            else
                war[x] = 1<<((maks - miss[x])/4);
            sum += war[x];
        }
        sum = losuj(sum);
        int co = -1;
        for(int x=0;x<a;x++)
        {
            if(sum <= war[x])
            {
                co = x;
                break;
            }
            sum -= war[x];
        }
        cout<<d[co]<<endl;
        cout.flush();
        char c;
        cin>>c;
        for(int x=0;x<a;x++)
            if(d[x] != c)
                miss[x]++;
    }
	return 0;
}